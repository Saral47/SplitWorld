#pragma once
#ifndef IObject_hpp
#define IObject_hpp

class IObject
{
public:
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clear() = 0;
};

#endif