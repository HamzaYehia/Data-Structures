#ifndef HASH_TABLE_H
#define HASH_TABLE_H



#define MAX_NAME 256
#define TABLE_SIZE 10



typedef struct person {
    char name[MAX_NAME];
    int age;
}person;

// array of pointers to person structs
person* hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] == NULL;
    }
}


void printTable() {
    printf("\tstart\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("\t%i\t---\n", i);
        }
        else {
            printf("\t%i\t%s\n", i, hashTable[i]->name);
        }
    }
    printf("\tend\n");
}

unsigned int hashToTable(const char* name) {

    int length = strnlen(name, MAX_NAME);
    unsigned int hashValue = 0;
    for (int i = 0; i < length; i++) {
        // generating random index to hash value to it
        hashValue += name[i];
        hashValue = (hashValue * name[i]) % TABLE_SIZE;
    }
    return hashValue;
}

bool insertInTable(person* p) {
    // error handling
    if (p == NULL) return false;

    int index = hashToTable(p->name);

    // check if index is not empty
    if (hashTable[index] != NULL) {
        return false;
    }
    // else: store the struct in index
    hashTable[index] = p;
    return true;
}


person* lookInHashTable(char* name) {
    int index = hashToTable(name);
    if (hashTable[index] != NULL && strncmp(name, hashTable[index]->name, MAX_NAME) == 0) {
        return hashTable[index];
    }
    else {
        printf("Item not found in Hash Table\n");
        return NULL;
    }
}



#endif