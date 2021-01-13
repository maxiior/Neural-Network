#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(string name, size_t layers, vector<size_t> numberOfNeurons)
{
	this->name = name;
	this->numberOfNeurons = numberOfNeurons;
	this->layers = layers;
	createLayers();
}
NeuralNetwork::NeuralNetwork()
{

}
NeuralNetwork::~NeuralNetwork()
{
	numberOfNeurons.clear();
	neuralLayers.clear();
}
void NeuralNetwork::createLayers()
{
	vector <Neuron> singleNeuralLayer;
	vector<Neuron> firstLayer;
	Neuron singleNeuron;

	for (size_t i = 0; i < numberOfNeurons[0]; i++)
	{
		singleNeuron.activation = 0.0f;
		firstLayer.push_back(singleNeuron);
	}

	neuralLayers.push_back(firstLayer);

	for (size_t i = 1; i < layers; i++)
	{
		for (size_t j = 0; j < numberOfNeurons[i]; j++)
		{
			for (size_t k = 0; k < numberOfNeurons[i - 1]; k++)
			{
				singleNeuron.weight.push_back((rand() % 101) / 100.0f);
			}
			if(i==1)singleNeuron.bias = 80.0f;
			else singleNeuron.bias = 5.0f;
			singleNeuralLayer.push_back(singleNeuron);
			singleNeuron.weight.clear();
		}
		neuralLayers.push_back(singleNeuralLayer);
		singleNeuralLayer.clear();
	}
}
void NeuralNetwork::loadActivations(string folderPath)
{
	fstream plik;
	size_t i = 0;

	plik.open(folderPath, ios::in);

	if (plik)
	{
		while (!plik.eof() && i < neuralLayers[0].size())
		{
			plik >> neuralLayers[0][i++].activation;
		}
	}
	else
		cerr << "Nie udalo sie odczytac wartosci aktywacyjnych! BLAD_" << folderPath;

	plik.close();
	plik.clear();
}
float NeuralNetwork::sigmoid(float x)
{
	return 1.0f / (1.0f + powf(M_E, -x));
}
float NeuralNetwork::sigmoidDerivative(float x)
{
	return sigmoid(x)*(1 - sigmoid(x));
}
void NeuralNetwork::enumerationOfActivation()
{
	float activationBufor = 0;

	for (size_t i = 1; i < neuralLayers.size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[i].size(); j++)
		{
			for (size_t k = 0; k < neuralLayers[i][j].weight.size(); k++)
			{
				activationBufor += neuralLayers[i][j].weight[k] * neuralLayers[i - 1][k].activation;
			}
			activationBufor -= neuralLayers[i][j].bias;
			activationBufor = NeuralNetwork::sigmoid(activationBufor);
			neuralLayers[i][j].activation = activationBufor;
			activationBufor = 0;
		}
	}
}
float NeuralNetwork::cost(size_t correctNumber)
{
	vector<float> costComponents;
	float cost = 0;

	for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 1].size(); i++)
	{
		if (i == correctNumber)
			costComponents.push_back(1);
		else
			costComponents.push_back(0);
	}

	for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 1].size(); i++)
	{
		cost += ((neuralLayers[neuralLayers.size() - 1][i].activation - costComponents[i])*(neuralLayers[neuralLayers.size() - 1][i].activation - costComponents[i]));
	}

	return cost;
}
float NeuralNetwork::effectivenessStudy(string folderPath, size_t numberOfExamples)
{
	float succesfull = 0;

	for (int i = 0; i < numberOfExamples; i++)
	{
		string a;
		a = to_string(i);
		loadActivations(folderPath + a + ".txt");
		enumerationOfActivation();

		int max = 0;
		float maxValue = neuralLayers[neuralLayers.size() - 1][0].activation;

		for (size_t j = 0; j < neuralLayers[neuralLayers.size() - 1].size(); j++)
		{
			if (neuralLayers[neuralLayers.size() - 1][j].activation > maxValue)
			{
				max = j; maxValue = neuralLayers[neuralLayers.size() - 1][j].activation;
			}
		}

		if (i == 0 && max == 0)
		{
			succesfull++;
		}
		else if (max == i % 10) succesfull++;
	}

	return (succesfull / numberOfExamples * 100.0f);
}
void NeuralNetwork::backPropagation(size_t correctNumber)
{
	float activationBufor = 0;
	vector<float> singleLayerSum;
	vector<vector<float>> sum;

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

	vector<vector<float>> layersOfWeightsBP;
	vector<float> singleLayerOfWeightsBP;

	vector<vector<float>> layersOfBiasesBP;
	vector<float> singleLayerOfBiasesBP;

	vector<vector<float>> layersOfCosts;
	vector<float> singleLayerOfCosts;
	float singleCost = 0;
	float check;

	for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 1].size(); i++)
	{
		if (i == correctNumber)
			check = 1;
		else
			check = 0;

		for (size_t j = 0; j < neuralLayers[neuralLayers.size() - 2].size(); j++)
		{
			singleLayerOfWeightsBP.push_back(neuralLayers[neuralLayers.size() - 2][j].activation*NeuralNetwork::sigmoidDerivative(sum[sum.size() - 1][i])*2.0f*(neuralLayers[neuralLayers.size() - 1][i].activation - check));
		}
	}
	layersOfWeightsBP.push_back(singleLayerOfWeightsBP);
	singleLayerOfWeightsBP.clear();

	for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 1].size(); i++)
	{
		if (i == correctNumber)
			check = 1;
		else
			check = 0;

		singleLayerOfBiasesBP.push_back(NeuralNetwork::sigmoidDerivative(sum[sum.size() - 1][i])*2.0f*(neuralLayers[neuralLayers.size() - 1][i].activation - check));
	}
	layersOfBiasesBP.push_back(singleLayerOfBiasesBP);
	singleLayerOfBiasesBP.clear();

	for (size_t i = 0; i < neuralLayers[neuralLayers.size() - 2].size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[neuralLayers.size() - 1].size(); j++)
		{
			if (j == correctNumber)
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
			layersOfWeightsBP.push_back(singleLayerOfWeightsBP);
			singleLayerOfWeightsBP.clear();

			for (size_t i = 0; i < neuralLayers[neuralLayers.size() - (q + 2)].size(); i++)
			{
				singleLayerOfBiasesBP.push_back(NeuralNetwork::sigmoidDerivative(sum[sum.size() - (q + 2)][i])*2.0f*layersOfCosts[q][i]);
			}
			layersOfBiasesBP.push_back(singleLayerOfBiasesBP);
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

	for (size_t i = 1; i < neuralLayers.size(); i++)
	{
		for (size_t j = 0; j < neuralLayers[neuralLayers.size() - i].size(); j++)
		{
			for (size_t k = 0; k < neuralLayers[neuralLayers.size() - i][j].weight.size(); k++)
			{
				neuralLayers[neuralLayers.size() - i][j].weight[k] -= layersOfWeightsBP[i - 1][k + (j*neuralLayers[neuralLayers.size() - i][j].weight.size())];
			}
			neuralLayers[neuralLayers.size() - i][j].bias -= layersOfBiasesBP[i - 1][j];
		}
	}
}
bool NeuralNetwork::verify()
{
	if ((!name.size()) && (!layers) && (!numberOfNeurons.size()))
	{
		return false;
	}
	else return true;
}
float NeuralNetwork::averageCost(string folderPath, size_t numberOfExamples)
{
	float sumcost = 0;

	for (int i = 0; i < numberOfExamples; i++)
	{
		string a;
		a = to_string(i);
		
		loadActivations(folderPath + a + ".txt");
		enumerationOfActivation();

		if(i==0) sumcost += cost(0);
		else sumcost += cost(i%neuralLayers[neuralLayers.size() - 1].size());
	}

	return floor((sumcost / numberOfExamples)*100.0f)/100.0f;
}
void NeuralNetwork::clear()
{
	name="";
	layers=0;
	numberOfNeurons.clear();
	neuralLayers.clear();
}