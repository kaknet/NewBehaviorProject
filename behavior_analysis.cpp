#ifndef BEHAVIOR_DEFINITIONS_H
#define BEHAVIOR_DEFINITIONS_H

#include <iostream>
#include <string>
using namespace std;

// Enum kwa viwango vya tabia
enum DisciplineLevel {
    LOW = 10,
    MEDIUM = 50,
    HIGH = 90
};

// Muundo wa binadamu na tabia zake
struct Person {
    string name;
    int age;
    DisciplineLevel exercises;
    DisciplineLevel swims;
    DisciplineLevel runs;
    DisciplineLevel faithful;
    DisciplineLevel sleepsEarly;
    DisciplineLevel smokes;
    DisciplineLevel socialLevel;
    DisciplineLevel decisionSpeed;
    DisciplineLevel eatingHabits;
    DisciplineLevel workEthic;
    DisciplineLevel creativity;
};

// Function ya kuchambua tabia
void analyzeBehavior(Person p);

#endif

#include "behavior_definitions.h"

void analyzeBehavior(Person p) {
    cout << "\n🔍 Tathmini ya tabia za " << p.name << ":" << endl;
    cout << "---------------------------------------" << endl;
    cout << "👤 Umri: " << p.age << " miaka\n";
    cout << "💪 Exercises: " << p.exercises << "%\n";
    cout << "🏊 Swims: " << p.swims << "%\n";
    cout << "🏃 Runs: " << p.runs << "%\n";
    cout << "❤️ Faithful: " << p.faithful << "%\n";
    cout << "🌙 Sleeps Early: " << p.sleepsEarly << "%\n";
    cout << "🚬 Smokes: " << p.smokes << "%\n";
    cout << "🤝 Social Level: " << p.socialLevel << "%\n";
    cout << "⚡ Decision Speed: " << p.decisionSpeed << "%\n";
    cout << "🍽️ Eating Habits: " << p.eatingHabits << "%\n";
    cout << "🏆 Work Ethic: " << p.workEthic << "%\n";
    cout << "🎨 Creativity: " << p.creativity << "%\n";
    cout << "---------------------------------------\n";
}

int main() {
    Person haruna = { 
        "Haruna Hussein", 25, HIGH, MEDIUM, HIGH, HIGH, LOW, LOW, MEDIUM, HIGH, MEDIUM, HIGH, HIGH 
    };

    analyzeBehavior(haruna);
    
    return 0;
}
