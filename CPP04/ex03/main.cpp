/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:14:17 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/01 21:16:43 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

void print_separator(const std::string& title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void test_basic_materia_creation()
{
	print_separator("TEST 1: Basic Materia Creation");
	
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	
	std::cout << "Ice type: " << ice->getType() << std::endl;
	std::cout << "Cure type: " << cure->getType() << std::endl;
	
	delete ice;
	delete cure;
}

void test_materia_clone()
{
	print_separator("TEST 2: Materia Clone");
	
	Ice* original = new Ice();
	AMateria* cloned = original->clone();
	
	std::cout << "Original type: " << original->getType() << std::endl;
	std::cout << "Cloned type: " << cloned->getType() << std::endl;
	std::cout << "Are they different objects? " << (original != cloned ? "Yes" : "No") << std::endl;
	
	delete original;
	delete cloned;
}

void test_character_creation()
{
	print_separator("TEST 3: Character Creation");
	
	std::string name1 = "John";
	std::string name2 = "Alice";
	
	Character* john = new Character(name1);
	Character* alice = new Character(name2);
	
	std::cout << "Character 1 name: " << john->getName() << std::endl;
	std::cout << "Character 2 name: " << alice->getName() << std::endl;
	
	delete john;
	delete alice;
}

void test_equip_and_use()
{
	print_separator("TEST 4: Equip and Use Materia");
	
	std::string name = "Bob";
	Character* bob = new Character(name);
	
	std::string targetName = "Enemy";
	Character* enemy = new Character(targetName);
	
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	
	std::cout << "\nEquipping Ice..." << std::endl;
	bob->equip(ice);
	
	std::cout << "\nEquipping Cure..." << std::endl;
	bob->equip(cure);
	
	std::cout << "\nUsing materia at index 1 on " << enemy->getName() << ":" << std::endl;
	bob->use(1, *enemy);
	
	std::cout << "\nUsing materia at index 2 on " << enemy->getName() << ":" << std::endl;
	bob->use(2, *enemy);
	
	delete bob;
	delete enemy;
}

void test_full_inventory()
{
	print_separator("TEST 5: Full Inventory");
	
	std::string name = "Warrior";
	Character* warrior = new Character(name);
	
	std::cout << "\nFilling inventory with 4 materias..." << std::endl;
	warrior->equip(new Ice());
	warrior->equip(new Cure());
	warrior->equip(new Ice());
	warrior->equip(new Cure());
	
	std::cout << "\nTrying to equip 5th materia (should fail)..." << std::endl;
	Ice* extraIce = new Ice();
	warrior->equip(extraIce);
	
	// If inventory is full, we need to delete the extra materia
	delete extraIce;
	delete warrior;
}

void test_unequip()
{
	print_separator("TEST 6: Unequip Materia");
	
	std::string name = "Mage";
	Character* mage = new Character(name);
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	mage->equip(ice);
	mage->equip(cure);
	
	std::cout << "\nUnequipping materia at index 1..." << std::endl;
	mage->unequip(1);
	
	std::cout << "\nTrying to use unequipped materia (should do nothing)..." << std::endl;
	std::string targetName = "Target";
	Character* target = new Character(targetName);
	mage->use(1, *target);
	
	// After unequip, we need to manually delete the materia to avoid leak
	delete ice;
	
	delete mage;
	delete target;
}

void test_materia_source()
{
	print_separator("TEST 7: MateriaSource Learn and Create");
	
	IMateriaSource* src = new MateriaSource();
	
	std::cout << "\nLearning Ice materia..." << std::endl;
	src->learnMateria(new Ice());
	
	std::cout << "\nLearning Cure materia..." << std::endl;
	src->learnMateria(new Cure());
	
	std::cout << "\nCreating Ice from source..." << std::endl;
	AMateria* ice = src->createMateria("Ice");
	std::cout << "Created materia type: " << (ice ? ice->getType() : "NULL") << std::endl;
	
	std::cout << "\nCreating Cure from source..." << std::endl;
	AMateria* cure = src->createMateria("Cure");
	std::cout << "Created materia type: " << (cure ? cure->getType() : "NULL") << std::endl;
	
	std::cout << "\nTrying to create unknown materia type..." << std::endl;
	AMateria* unknown = src->createMateria("Fire");
	std::cout << "Created materia: " << (unknown ? "Success" : "NULL (expected)") << std::endl;
	
	delete ice;
	delete cure;
	delete src;
}

void test_character_deep_copy()
{
	print_separator("TEST 8: Character Deep Copy");
	
	std::string name1 = "Original";
	Character* original = new Character(name1);
	original->equip(new Ice());
	original->equip(new Cure());
	
	std::cout << "\nCreating copy of character..." << std::endl;
	Character* copy = new Character(*original);
	
	std::cout << "Original name: " << original->getName() << std::endl;
	std::cout << "Copy name: " << copy->getName() << std::endl;
	
	std::string targetName = "Target";
	Character* target = new Character(targetName);
	
	std::cout << "\nUsing materia from original:" << std::endl;
	original->use(1, *target);
	
	std::cout << "\nUsing materia from copy:" << std::endl;
	copy->use(1, *target);
	
	delete original;
	delete copy;
	delete target;
}

void test_complete_scenario()
{
	print_separator("TEST 9: Complete Combat Scenario");
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::string name1 = "Hero";
	std::string name2 = "Villain";
	ICharacter* hero = new Character(name1);
	ICharacter* villain = new Character(name2);
	
	std::cout << "\nHero equips materias..." << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("Ice");
	hero->equip(tmp);
	tmp = src->createMateria("Cure");
	hero->equip(tmp);
	tmp = src->createMateria("Ice");
	hero->equip(tmp);
	
	std::cout << "\nHero uses Ice on Villain:" << std::endl;
	hero->use(1, *villain);
	
	std::cout << "\nHero uses Cure on themselves:" << std::endl;
	hero->use(2, *hero);
	
	std::cout << "\nHero uses another Ice on Villain:" << std::endl;
	hero->use(3, *villain);
	
	std::cout << "\nTrying to use empty slot (should do nothing):" << std::endl;
	hero->use(4, *villain);
	
	delete hero;
	delete villain;
	delete src;
}

void test_edge_cases()
{
	print_separator("TEST 10: Edge Cases");
	
	std::string name = "Tester";
	Character* tester = new Character(name);
	
	std::cout << "\nTrying to equip NULL materia..." << std::endl;
	tester->equip(NULL);
	
	std::cout << "\nTrying to use invalid index 0..." << std::endl;
	tester->use(0, *tester);
	
	std::cout << "\nTrying to use invalid index 5..." << std::endl;
	tester->use(5, *tester);
	
	std::cout << "\nTrying to unequip invalid index 0..." << std::endl;
	tester->unequip(0);
	
	std::cout << "\nTrying to unequip invalid index 5..." << std::endl;
	tester->unequip(5);
	
	delete tester;
}

int main()
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   MATERIA SYSTEM - COMPREHENSIVE TESTS ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝" << std::endl;
	
	test_basic_materia_creation();
	test_materia_clone();
	test_character_creation();
	test_equip_and_use();
	test_full_inventory();
	test_unequip();
	test_materia_source();
	test_character_deep_copy();
	test_complete_scenario();
	test_edge_cases();
	
	print_separator("ALL TESTS COMPLETED");
	return (0);
}
