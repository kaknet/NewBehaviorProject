#ifndef BEHAVIOR_DEFINITIONS_H
#define BEHAVIOR_DEFINITIONS_H

#include <iostream>
#include <string>
using namespace std;

enum DisciplineLevel {
    LOW = 25,
    MEDIUM = 67,
    HIGH = 87
};

struct Person {
    string name;
    DisciplineLevel exercises;
    DisciplineLevel swims;
    DisciplineLevel runs;
    DisciplineLevel faithful;
    DisciplineLevel sleepsEarly;
    DisciplineLevel smokes;
    DisciplineLevel socialLevel;
    DisciplineLevel decisionSpeed;
};

// Function ya kuchambua tabia
void analyzeBehavior(Person p);

#endif

#include "behavior_definitions.h"

void analyzeBehavior(Person p) {
    cout << "Tathmini ya tabia za " << p.name << ":" << endl;
    cout << "- Exercises: " << p.exercises << "%\n";
    cout << "- Swims: " << p.swims << "%\n";
    cout << "- Runs: " << p.runs << "%\n";
    cout << "- Faithful: " << p.faithful << "%\n";
    cout << "- Sleeps Early: " << p.sleepsEarly << "%\n";
    cout << "- Smokes: " << p.smokes << "%\n";
    cout << "- Social Level: " << p.socialLevel << "%\n";
    cout << "- Decision Speed: " << p.decisionSpeed << "%\n";
}

int main() {
    Person haruna = { 
        "Haruna Hussein", HIGH, MEDIUM, HIGH, HIGH, LOW, LOW, MEDIUM, HIGH 
    };

    analyzeBehavior(haruna);
    
    return 0;
}

