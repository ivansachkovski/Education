#pragma once

class IAnimal
{
public:
	virtual std::string GetInfo() = 0;
};

class CCat :
	public IAnimal
{
	std::string GetInfo() override
	{
		return "It's a cat";
	}
};

class CDog :
	public IAnimal
{
	std::string GetInfo() override
	{
		return "It's a dog";
	}
};

class IFactory
{
public:
	virtual IAnimal* CreateAnimal() = 0;
};

class CCatFactory :
	public IFactory
{
	IAnimal* CreateAnimal() override
	{
		return new CCat();
	}
};

class CDogFactory :
	public IFactory
{
	IAnimal* CreateAnimal() override
	{
		return new CDog();
	}
};