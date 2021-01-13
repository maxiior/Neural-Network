#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#define M_E 2.71828182845904523536

using namespace std;

class Neuron
{
public:
	float bias;
	float activation;
	vector<float> weight;
};

class NeuralNetwork
{
private:
	string name;
	void createLayers();
	float cost(size_t correctNumber);

public:
	NeuralNetwork();
	NeuralNetwork(string name, size_t layers, vector<size_t> numberOfNeurons);
	~NeuralNetwork();

	size_t layers;
	vector<size_t> numberOfNeurons;
	vector<vector<Neuron>> neuralLayers;

	bool verify();
	float sigmoid(float x);
	float sigmoidDerivative(float x);
	float averageCost(string folderPath, size_t numberOfExamples);
	float effectivenessStudy(string folderPath, size_t numberOfExamples);
	void clear();
	void enumerationOfActivation();
	void loadActivations(string folderPath);
	void backPropagation(size_t correctNumber);

	void SAVE(string folderPath);
	void STATISTICS(string folderPath, size_t numberOfExamples);
	void CREATE(string name, size_t layers, vector<size_t> numberOfNeurons);
	void LINEAR_LEARNING(string folderPath, size_t numberOfExamples, size_t targetEffectiveness);
	void RANDOM_LEARNING(string folderPath, size_t numberOfExamples, size_t targetEffectiveness);
	void ADVANCED_LEARNING(string folderPath, size_t numberOfExamples, size_t targetEffectiveness);
	bool LOAD(string folderPath);
	int RECOGNIZE(string folderPath);
};