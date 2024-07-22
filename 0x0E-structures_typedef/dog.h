#ifndef DOG_H
#define DOG_H
/**
 * struct dog - initializes the struct
 *
 * @name: Dog's name
 * @age: Dog's age
 * @owner: name of dog's owner
 *
 * Description: learning struct
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif
