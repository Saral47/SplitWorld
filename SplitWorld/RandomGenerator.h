#pragma once
#ifndef RandomGenerator_hpp
#define RandomGenerator_hpp
#include<random>
class RandomGenerator
{
private:
	static RandomGenerator* instance;
	RandomGenerator();

public:
	inline static RandomGenerator* GetInstance() { if (!instance) { instance = new RandomGenerator; }  return instance; };
	int RandomRange(int a, int b);
};

#endif

