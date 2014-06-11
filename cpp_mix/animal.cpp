#include "animal.h"

void  Animal::setAge(int new_age) { this->age = new_age; }
int   Animal::getAge() { return this->age; }
void  Animal::setHeight(float new_height) { this->height = new_height; }
float Animal::getHeight() { return this->height; }

Animal *animal_create() {
    Animal *a = new Animal;
    return a;
}

Animal *animal_create_init(int age, float height) {
    Animal *a = new Animal(age, height);
    return a;
}

void animal_destroy(Animal *a) {
    delete (a);
}

void animal_setage(Animal *a, int new_age) {
    (a)->setAge(new_age);
}

void animal_setheight(Animal *a, float new_height) {
    (a)->setHeight(new_height);
}

int animal_getage(Animal *a) {
    return (a)->getAge();
}

float animal_getheight(Animal *a) {
    return (a)->getHeight();
}
