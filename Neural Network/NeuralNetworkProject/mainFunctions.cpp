#include "NeuralNetwork.h"
void NeuralNetwork::CREATE(string name, size_t layers, vector<size_t> numberOfNeurons)
{
	this->name = name;
	this->numberOfNeurons = numberOfNeurons;
	this->layers = layers;
	createLayers();
}
int NeuralNetwork::RECOGNIZE(string folderPath)
{
	loadActivations(folderPath);
	enumerationOfActivation();

	vector<float>costs;
	float min;
	int imin = 0;

	for (int i = 0; i < 10; i++)
	{
		costs.push_back(cost(i));

		if (i == 0)
		{
			min = costs[i];
			imin = 0;
		}

		if (min > costs[i])
		{
			min = costs[i];
			imin = i;
		}
	}

	return imin;
}
void NeuralNetwork::SAVE(string folderPath)
{
	fstream plik;
	string a, b;

	plik.open(folderPath + "spec.txt", ios::out | ios::trunc);
	plik.close();
	plik.clear();

	plik.open(folderPath + "spec.txt", ios::out | ios::app);

	plik << this->name << endl;
	plik << this->layers << endl;

	for (int i = 0; i < layers; i++)
	{
		if(i==layers-1) plik << this->numberOfNeurons[i];
		else plik << this->numberOfNeurons[i] << endl;
	}
		

	plik.close();
	plik.clear();

	for (size_t i = 1; i < neuralLayers.size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[i].size(); j++)
		{
			a = to_string(i);
			b = to_string(j);

			plik.open(folderPath + a + "_" + b + "weights.txt", ios::out | ios::trunc);
			plik.close();
			plik.clear();

			plik.open(folderPath + a + "_" + b + "weights.txt", ios::out | ios::app);
			for (size_t k = 0; k < neuralLayers[i][j].weight.size(); k++)
			{
				plik << neuralLayers[i][j].weight[k] << endl;
			}
			plik.close();
			plik.clear();
		}
	}

	plik.open(folderPath + "biases.txt", ios::out | ios::trunc);
	plik.close();
	plik.clear();

	plik.open(folderPath + "biases.txt", ios::out | ios::app);
	for (size_t i = 1; i < neuralLayers.size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[i].size(); j++)
		{
			plik << neuralLayers[i][j].bias << endl;
		}
	}
	plik.close();
	plik.clear();
}
bool NeuralNetwork::LOAD(string folderPath)
{
	fstream plik;
	string a, b;
	float x;

	plik.open(folderPath + "spec.txt", ios::in);

	if (!plik.good()) return false;

	plik >> name;
	plik >> layers;

	for (int i = 0; i < layers; i++)
	{
		int j;
		plik >> j;
		numberOfNeurons.push_back(j);
	}

	plik.close();
	plik.clear();
	
	createLayers();

	for (size_t i = 1; i < neuralLayers.size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[i].size(); j++)
		{
			a = to_string(i);
			b = to_string(j);

			plik.open(folderPath + a + "_" + b + "weights.txt", ios::in);

			if (!plik.good()) return false;

			for (size_t k = 0; k < neuralLayers[i][j].weight.size(); k++)
			{
				plik >> x;
				neuralLayers[i][j].weight[k] = x;
			}
			plik.close();
			plik.clear();
		}
	}

	plik.open(folderPath + "biases.txt", ios::in);

	if (!plik.good()) return false;

	for (size_t i = 1; i < neuralLayers.size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[i].size(); j++)
			plik >> neuralLayers[i][j].bias;
	}
	plik.close();
	plik.clear();

	return true;
}
void NeuralNetwork::STATISTICS(string folderPath, size_t numberOfExamples)
{
	cout << "Effectiveness: " << effectivenessStudy(folderPath, numberOfExamples) << "%" << endl;
	cout << endl;
	cout << "AVERAGE COST: " << averageCost(folderPath, numberOfExamples) << endl;
}
void NeuralNetwork::LINEAR_LEARNING(string folderPath, size_t numberOfExamples, size_t targetEffectiveness)
{
	while (true)
	{
		for (int i = 0; i < numberOfExamples; i++)
		{
			string a;
			a = to_string(i);
			loadActivations(folderPath + a + ".txt");
			enumerationOfActivation();
			if(i==0) backPropagation(0);
			else backPropagation(i % 10);
		}
		if (effectivenessStudy(folderPath, numberOfExamples) >= targetEffectiveness) break;
	}
}
void NeuralNetwork::RANDOM_LEARNING(string folderPath, size_t numberOfExamples, size_t targetEffectiveness)
{
	while (true)
	{
		for (int i = 0; i < numberOfExamples; i++)
		{
			size_t tmp = rand() % numberOfExamples;
			string a;
			a = to_string(tmp);
			loadActivations(folderPath + a + ".txt");
			enumerationOfActivation();
			if (i == 0) backPropagation(0);
			else backPropagation(i % 10);
		}
		if (effectivenessStudy(folderPath, numberOfExamples) >= targetEffectiveness) break;
	}
}
void NeuralNetwork::ADVANCED_LEARNING(string folderPath, size_t numberOfExamples, size_t targetEffectiveness)
{
	vector<vector<int>>stacksOfExamples;
	vector<int>singleStack;
	vector<int>tmp;

	float activationBufor = 0;
	vector<float> singleLayerSum;
	vector<vector<float>> sum;

	vector<vector<float>> layersOfWeightsBP;
	vector<float> singleLayerOfWeightsBP;

	vector<vector<float>> layersOfBiasesBP;
	vector<float> singleLayerOfBiasesBP;

	vector<vector<float>> layersOfCosts;
	vector<float> singleLayerOfCosts;
	float singleCost = 0;
	float check;

	while (true)
	{
		for (int i = 0; i < ceil(numberOfExamples / 30.0f); i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (tmp.size() == 0)
				{
					for (int q = 0; q < numberOfExamples; q++)
					{
						tmp.push_back(q);
					}
				}
				int k = rand() % tmp.size();
				singleStack.push_back(tmp[k]);
				tmp.erase(tmp.begin() + k);
			}
			stacksOfExamples.push_back(singleStack);
			singleStack.clear();
		}

		for (int g = 0; g < stacksOfExamples.size(); g++)
		{
			for (int g1 = 0; g1 < 30; g1++)
			{
				string a;
				a = to_string(stacksOfExamples[g][g1]);
				loadActivations(folderPath + a + ".txt");
				enumerationOfActivation();

				//BACKPROPAGATION
				for (size_t i = 1; i < neuralLayers.size(); i++)
				{
					for (size_t j = 0; j < neuralLayers[i].size(); j++)
					{
						for (size_t k = 0; k < neuralLayers[i][j].weight.size(); k++)
							activationBufor += neuralLayers[i][j].weight[k] * neuralLayers[i - 1][k].activation;

						activationBufor -= neuralLayers[i][j].bias;
						singleLayerSum.push_back(activationBufor);
						activationBufor = 0;
					}
					sum.push_back(singleLayerSum);
					singleLayerSum.clear();
				}
				for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 1].size(); i++)
				{
					if(i==0 && stacksOfExamples[g][g1] % 10==10)
						check = 1;
					else if (i == stacksOfExamples[g][g1] % 10)
						check = 1;
					else
						check = 0;

					for (size_t j = 0; j < neuralLayers[neuralLayers.size() - 2].size(); j++)
					{
						singleLayerOfWeightsBP.push_back(neuralLayers[neuralLayers.size() - 2][j].activation*NeuralNetwork::sigmoidDerivative(sum[sum.size() - 1][i])*2.0f*(neuralLayers[neuralLayers.size() - 1][i].activation - check));
					}
				}
				if (g1 == 0)layersOfWeightsBP.push_back(singleLayerOfWeightsBP);
				else
				{
					for (int l = 0; l < layersOfWeightsBP[0].size(); l++)
					{
						layersOfWeightsBP[0][l] += singleLayerOfWeightsBP[l];
					}
				}
				singleLayerOfWeightsBP.clear();
				for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 1].size(); i++)
				{
					if (i == 0 && stacksOfExamples[g][g1] % 10 == 10)
						check = 1;
					else if (i == stacksOfExamples[g][g1] % 10)
						check = 1;
					else
						check = 0;

					singleLayerOfBiasesBP.push_back(NeuralNetwork::sigmoidDerivative(sum[sum.size() - 1][i])*2.0f*(neuralLayers[neuralLayers.size() - 1][i].activation - check));
				}
				if (g1 == 0)layersOfBiasesBP.push_back(singleLayerOfBiasesBP);
				else
				{
					for (int l = 0; l < layersOfBiasesBP[0].size(); l++)
					{
						layersOfBiasesBP[0][l] += singleLayerOfBiasesBP[l];
					}
				}
				singleLayerOfBiasesBP.clear();
				for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 2].size(); i++)
				{
					for (size_t j = 0; j < neuralLayers[neuralLayers.size() - 1].size(); j++)
					{
						if (i == 0 && stacksOfExamples[g][g1] % 10 == 10)
							check = 1;
						else if (i == stacksOfExamples[g][g1] % 10)
							check = 1;
						else
							check = 0;

						singleCost += neuralLayers[neuralLayers.size() - 1][j].weight[i] * NeuralNetwork::sigmoidDerivative(sum[sum.size() - 1][j])*2.0f*(neuralLayers[neuralLayers.size() - 1][j].activation - check);
					}
					singleLayerOfCosts.push_back(singleCost);
					singleCost = 0;
				}
				layersOfCosts.push_back(singleLayerOfCosts);
				singleLayerOfCosts.clear();
				if (neuralLayers.size() > 2)
				{
					for (size_t q = 0; q < neuralLayers.size() - 2; q++)
					{
						for (size_t i = 0; i < neuralLayers[neuralLayers.size() - (q + 2)].size(); i++)
						{
							for (size_t j = 0; j < neuralLayers[neuralLayers.size() - (q + 3)].size(); j++)
							{
								singleLayerOfWeightsBP.push_back(neuralLayers[neuralLayers.size() - (q + 3)][j].activation*NeuralNetwork::sigmoidDerivative(sum[sum.size() - (q + 2)][i])*2.0f*layersOfCosts[q][i]);
							}
						}
						if (g1 == 0)layersOfWeightsBP.push_back(singleLayerOfWeightsBP);
						else
						{
							for (int l = 0; l < layersOfWeightsBP[q + 1].size(); l++)
							{
								layersOfWeightsBP[q + 1][l] += singleLayerOfWeightsBP[l];
							}
						}
						singleLayerOfWeightsBP.clear();

						for (size_t i = 0; i < neuralLayers[neuralLayers.size() - (q + 2)].size(); i++)
						{
							singleLayerOfBiasesBP.push_back(NeuralNetwork::sigmoidDerivative(sum[sum.size() - (q + 2)][i])*2.0f*layersOfCosts[q][i]);
						}
						if (g1 == 0)layersOfBiasesBP.push_back(singleLayerOfBiasesBP);
						else
						{
							for (int l = 0; l < layersOfBiasesBP[q + 1].size(); l++)
							{
								layersOfBiasesBP[q + 1][l] += singleLayerOfBiasesBP[l];
							}
						}
						singleLayerOfBiasesBP.clear();

						if (q < (neuralLayers.size() - 1))
						{
							for (size_t i = 0; i < neuralLayers[neuralLayers.size() - (q + 3)].size(); i++)
							{
								for (size_t j = 0; j < neuralLayers[neuralLayers.size() - (q + 2)].size(); j++)
								{
									singleCost += neuralLayers[neuralLayers.size() - 2 - q][j].weight[i] * NeuralNetwork::sigmoidDerivative(sum[sum.size() - (q + 2)][j])*2.0f*layersOfCosts[q][j];
								}
								singleLayerOfCosts.push_back(singleCost);
								singleCost = 0;
							}
							layersOfCosts.push_back(singleLayerOfCosts);
							singleLayerOfCosts.clear();
						}
					}
				}
				//BACKPROPAGATION
			}
			for (size_t i = 1; i < neuralLayers.size(); i++)
			{
				for (size_t j = 0; j < neuralLayers[neuralLayers.size() - i].size(); j++)
				{
					for (size_t k = 0; k < neuralLayers[neuralLayers.size() - i][j].weight.size(); k++)
					{
						neuralLayers[neuralLayers.size() - i][j].weight[k] -= (layersOfWeightsBP[i - 1][k + (j*neuralLayers[neuralLayers.size() - i][j].weight.size())]) / 30;
					}
					neuralLayers[neuralLayers.size() - i][j].bias -= (layersOfBiasesBP[i - 1][j]) / 30;
				}
			}
			layersOfWeightsBP.clear();
			layersOfBiasesBP.clear();
		}

		stacksOfExamples.clear();

		if (effectivenessStudy(folderPath, numberOfExamples) >= targetEffectiveness) break;
		cout << "ATTEMPT: " << effectivenessStudy(folderPath, numberOfExamples) << "%" << endl;
	}
}