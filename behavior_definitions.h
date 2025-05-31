#ifndef BEHAVIOR_DEFINITIONS_H
#define BEHAVIOR_DEFINITIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 1. KUONGEZA TABIA MPYA ZA KIISLAMU
enum DisciplineLevel {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75,
    EXCELLENT = 90
};

// 2. KUONGEZA MAUDHUI YA KIROHO
struct SpiritualTraits {
    int prayerConsistency;       // Mara za kuswali kwa siku
    int quranReadingFrequency;   // Mara za kusoma Qur'an kwa wiki
    bool givesCharity;           // Sadaka ya kila mwezi
    string religiousKnowledge;   // "Beginner", "Intermediate", "Advanced"
};

// 3. KUONGEZA HISIA ZA KIJAMII
struct EmotionalTraits {
    int empathyLevel;
    int patienceLevel;
    bool controlsAnger;
    string conflictResolution; // "Avoidant", "Diplomatic", "Confrontational"
};

// 4. STRUCT KUU ILIYOBORESWA
struct Person {
    string name;
    int age;
    string occupation;
    
    // Tabia za kimwili
    DisciplineLevel exercises;
    DisciplineLevel swims;
    DisciplineLevel runs;
    
    // Tabia za kiroho
    SpiritualTraits faith;
    
    // Tabia za kijamii
    EmotionalTraits emotions;
    DisciplineLevel socialLevel;
    
    // Tabia za maamuzi
    DisciplineLevel decisionSpeed;
    string decisionStyle; // "Analytical", "Intuitive", "Impulsive"
};

// 5. FUNCTIONS MPYA
void generateReport(Person p);
void suggestImprovements(Person p);
void compareWithIdeal(Person p);

#endif
