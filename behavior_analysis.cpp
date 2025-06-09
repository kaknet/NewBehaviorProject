// behavior_analysis.cpp - Msimbo Mzima wa Tathmini ya Tabia za Binadamu na Kipengele cha Kiislamu
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// 1. Ufafanuzi wa Tabia za Msingi
enum DisciplineLevel {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75,
    EXCELLENT = 90
};

// 2. Tabia za Kiroho na Kiislamu
struct SpiritualTraits {
    int prayerConsistency;       // Mara za kuswali kwa siku (0-5)
    int quranReadingFrequency;   // Mara za kusoma Qur'an kwa wiki
    bool givesCharity;           // Sadaka ya kila mwezi
    string religiousKnowledge;   // "Beginner", "Intermediate", "Advanced"
    
    double calculateSpiritualWellness() const {
        double score = (prayerConsistency * 0.4) + 
                      (quranReadingFrequency * 0.3) + 
                      (givesCharity * 20) + 
                      (religiousKnowledge == "Advanced" ? 10 : 
                       religiousKnowledge == "Intermediate" ? 5 : 0);
        return min(100.0, score);
    }
};

// 3. Hisia za Kijamii
struct EmotionalTraits {
    int empathyLevel;            // 0-100
    int patienceLevel;           // 0-100
    bool controlsAnger;          // Anaweza kudhibiti ghadhabu
    string conflictResolution;   // "Avoidant", "Diplomatic", "Confrontational"
    
    double calculateEmotionalIQ() const {
        return (empathyLevel * 0.4 + patienceLevel * 0.4 + 
               (controlsAnger ? 20 : 0));
    }
};

// 4. Tabia za Maamuzi na Usalama wa Mtandao
struct DecisionTraits {
    DisciplineLevel decisionSpeed;
    string decisionStyle;        // "Analytical", "Intuitive", "Impulsive"
    double securityAwareness;    // 0-100
    
    double evaluateSecurityDecisions() const {
        double base = securityAwareness;
        if (decisionStyle == "Analytical") base *= 1.2;
        else if (decisionStyle == "Impulsive") base *= 0.7;
        return min(100.0, base);
    }
};

// 5. Muundo Mkuu wa Mtu
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
    
    // Tabia za maamuzi na usalama
    DecisionTraits decisions;
    
    double calculateTotalWellness() const {
        return (faith.calculateSpiritualWellness() * 0.4 +
               emotions.calculateEmotionalIQ() * 0.3 +
               decisions.evaluateSecurityDecisions() * 0.3);
    }
};

// 6. Kazi za Uchambuzi na Ripoti
void generateReport(const Person& p) {
    cout << "\n=== RIPOTI YA TABIA ZA " << p.name << " ===\n";
    cout << "Umri: " << p.age << " | Kazi: " << p.occupation << "\n\n";
    
    // Ripoti ya Kiroho
    cout << "--- KIROHO ---\n";
    cout << "Ustawi wa Kiroho: " << fixed << setprecision(1) 
         << p.faith.calculateSpiritualWellness() << "/100\n";
    cout << "Sala: " << p.faith.prayerConsistency << "/5 kwa siku\n";
    cout << "Kusoma Qur'an: " << p.faith.quranReadingFrequency << "x kwa wiki\n";
    cout << "Sadaka: " << (p.faith.givesCharity ? "Anatoa" : "Hatoi") << "\n";
    cout << "Elimu ya Dini: " << p.faith.religiousKnowledge << "\n";
    
    // Ripoti ya Kijamii
    cout << "\n--- KIJAMII ---\n";
    cout << "Ustawi wa Kihisia: " << p.emotions.calculateEmotionalIQ() << "/100\n";
    cout << "Uelewa: " << p.emotions.empathyLevel << "/100\n";
    cout << "Uvumilivu: " << p.emotions.patienceLevel << "/100\n";
    cout << "Udhibiti wa Ghadhabu: " << (p.emotions.controlsAnger ? "Nzuri" : "Haifai") << "\n";
    cout << "Uamuzi wa Migogoro: " << p.emotions.conflictResolution << "\n";
    
    // Ripoti ya Usalama
    cout << "\n--- USALAMA NA MAAMUZI ---\n";
    cout << "Ufahamu wa Usalama: " << p.decisions.evaluateSecurityDecisions() << "/100\n";
    cout << "Mbinu ya Uamuzi: " << p.decisions.decisionStyle << "\n";
    cout << "Haraka ya Uamuzi: " << p.decisions.decisionSpeed << "/100\n";
    
    // Jumla
    cout << "\n--- JUMLA ---\n";
    cout << "Ustawi wa Jumla: " << p.calculateTotalWellness() << "/100\n";
}

void suggestImprovements(const Person& p) {
    cout << "\n=== MAPENDEKEZO YA UBORESHAJI ===";
    
    // Mapendekezo ya kiroho
    if (p.faith.calculateSpiritualWellness() < 70) {
        cout << "\n[KIROHO] ";
        if (p.faith.prayerConsistency < 3) 
            cout << "Zidisha idadi ya sala kwa siku. ";
        if (p.faith.quranReadingFrequency < 3) 
            cout << "Soma Qur'an mara nyingi zaidi. ";
        if (!p.faith.givesCharity) 
            cout << "Fikiria kutoa sadaka mara kwa mara. ";
    }
    
    // Mapendekezo ya kijamii
    if (p.emotions.calculateEmotionalIQ() < 70) {
        cout << "\n[KIJAMII] ";
        if (p.emotions.empathyLevel < 50) 
            cout << "Jaribu kuelewa hisia za wengine zaidi. ";
        if (p.emotions.patienceLevel < 50) 
            cout << "Zoeza uvumilivu katika mazingira mbalimbali. ";
        if (!p.emotions.controlsAnger) 
            cout << "Jifunze mbinu za kudhibiti ghadhabu. ";
    }
    
    // Mapendekezo ya usalama
    if (p.decisions.evaluateSecurityDecisions() < 70) {
        cout << "\n[USALAMA] ";
        if (p.decisions.decisionStyle == "Impulsive")
            cout << "Jaribu kuchambua mambo kwa makini kabla ya kufanya uamuzi. ";
        if (p.decisions.securityAwareness < 50)
            cout << "Jifunze zaidi kuhusu usalama wa mtandao na mbinu za udanganyifu. ";
    }
    cout << "\n";
}

void analyzeSecurityBehavior(const Person& p) {
    cout << "\n=== UCHAMBUZI WA TABIA ZA USALAMA ===\n";
    
    // Uchambuzi wa mfumo wa kufanya maamuzi
    cout << "Mfumo wa Uamuzi: ";
    if (p.decisions.decisionStyle == "Analytical") {
        cout << "Unachambua kwa makini - hii ni nzuri kwa usalama.\n";
    } else if (p.decisions.decisionStyle == "Intuitive") {
        cout << "Unategemea hisia - waweza kukumbwa na udanganyifu wa kisaikolojia.\n";
    } else {
        cout << "Unafanya maamuzi ya haraka - hatari kubwa kwa usalama wa mtandao.\n";
    }
    
    // Uchambuzi wa uelewa wa usalama
    if (p.decisions.securityAwareness > 75) {
        cout << "Ufahamu wako wa usalama wa mtandao ni wa hali ya juu. ";
        cout << "Unaweza kusaidia wengine kujilinda.\n";
    } else if (p.decisions.securityAwareness > 50) {
        cout << "Una ufahamu wa kutosha wa usalama, lakini bado kuna mambo ya kujifunza.\n";
    } else {
        cout << "Ufahamu wako wa usalama wa mtandao ni wa chini. ";
        cout << "Ni muhimu kujifunza zaidi kuhusu udanganyifu wa mtandaoni.\n";
    }
    
    // Uhusiano kati ya imani na usalama
    if (p.faith.calculateSpiritualWellness() > 70 && p.decisions.securityAwareness < 50) {
        cout << "\n[TAHADHARI] Ingawa una imani nzuri, ufahamu wako wa usalama wa mtandao ni wa chini.\n";
        cout << "Watu wenye imani mara nyingi huwa lengo la udanganyifu wa kiroho mtandaoni.\n";
    }
}

// 7. Programu Kuu
int main() {
    // Mfano wa mtumiaji
    Person user = {
        "Ahmed", 28, "Mhandisi wa Programu",
        MEDIUM, LOW, MEDIUM,         // Kimwili
        {4, 3, true, "Intermediate"}, // Kiroho
        {70, 60, false, "Avoidant"}, // Kijamii
        MEDIUM,                      // Kiuchumi
        {MEDIUM, "Intuitive", 65}    // Maamuzi
    };
    
    // Mfano wa mtu bora wa Kiislamu
    Person idealMuslim = {
        "Mfano Bora", 30, "Mtaalamu wa Teknolojia",
        HIGH, MEDIUM, HIGH,          // Kimwili
        {5, 7, true, "Advanced"},    // Kiroho
        {90, 85, true, "Diplomatic"}, // Kijamii
        HIGH,                         // Kiuchumi
        {HIGH, "Analytical", 80}      // Maamuzi
    };
    
    // Kutengeneza ripoti
    generateReport(user);
    suggestImprovements(user);
    
    // Kulinganisha na mfano bora
    cout << "\n=== LINGANISHO NA MFANO BORA ===\n";
    cout << "Ustawi wako: " << user.calculateTotalWellness() << "/100\n";
    cout << "Ustawi wa Mfano Bora: " << idealMuslim.calculateTotalWellness() << "/100\n";
    
    // Uchambuzi maalum wa usalama
    analyzeSecurityBehavior(user);
    
    return 0;
}
