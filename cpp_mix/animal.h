#ifndef ANIMAL_H
#define ANIMAL_H

#ifdef __cplusplus
class Animal {
  public:
    Animal() : age(0), height(0) {}
    Animal(int age, float height) : age(age), height(height) {}
    virtual ~Animal() {}

    int   getAge();
    void  setAge(int new_age);

    float getHeight();
    void  setHeight(float new_height);

  private:
    int age;
    float height; // in metres!
};
#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct Animal Animal; // a nice opaque type

    Animal *animal_create();
    Animal *animal_create_init(int age, float height);
    void    animal_destroy(Animal *a);

    void    animal_setage(Animal *a, int new_age);
    void    animal_setheight(Animal *a, float new_height);
    int     animal_getage(Animal *a);
    float   animal_getheight(Animal *a);
#ifdef __cplusplus
}
#endif

#endif /* ANIMAL_H */
