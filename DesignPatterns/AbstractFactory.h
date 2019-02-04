#pragma once

class IPerson
{
public:
	virtual std::string GetInfo() = 0;
};

class CMan :
	public IPerson
{
public:
	std::string GetInfo() override
	{
		return "I'm a man";
	}
};

class CWoman :
	public IPerson
{
public:
	std::string GetInfo() override
	{
		return "I'm a woman";
	}
};

class IAbstractFactory
{
public:
	virtual IPerson* CreatePerson() = 0;
	virtual IAnimal* CreateAnimal() = 0;
};

class CManAndDogFactory :
	public IAbstractFactory
{
public:
	IPerson* CreatePerson() override
	{
		return new CMan();
	}

	IAnimal* CreateAnimal() override
	{
		return new CDog();
	}
};

class CWomanAndCatFactory :
	public IAbstractFactory
{
public:
	IPerson* CreatePerson() override
	{
		return new CWoman();
	}

	IAnimal* CreateAnimal() override
	{
		return new CCat();
	}
};