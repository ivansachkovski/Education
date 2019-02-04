#include "pch.h"

TEST(FactoryMethodPattern, Factory) {
	
	IFactory* pCatFactory = new CCatFactory();
	IFactory* pDogFactory = new CDogFactory();
	
	IAnimal* pCat = pCatFactory->CreateAnimal();
	IAnimal* pDog = pDogFactory->CreateAnimal();

	EXPECT_EQ("It's a cat", pCat->GetInfo());
	EXPECT_EQ("It's a dog", pDog->GetInfo());
}

TEST(AbstractFactoryPattern, ManAndDogFactory) {

	IAbstractFactory* pManAndDogFactory = new CManAndDogFactory();

	IPerson* pPerson = pManAndDogFactory->CreatePerson();
	IAnimal* pAnimal = pManAndDogFactory->CreateAnimal();

	EXPECT_EQ("It's a dog", pAnimal->GetInfo());
	EXPECT_EQ("I'm a man", pPerson->GetInfo());
}

TEST(AbstractFactoryPattern, WomanAndCatFactory) {

	IAbstractFactory* pWomanAndCatFactory = new CWomanAndCatFactory();

	IPerson* pPerson = pWomanAndCatFactory->CreatePerson();
	IAnimal* pAnimal = pWomanAndCatFactory->CreateAnimal();

	EXPECT_EQ("It's a cat", pAnimal->GetInfo());
	EXPECT_EQ("I'm a woman", pPerson->GetInfo());
}