#include <iostream>
using namespace std;

class Field : public Flower{
    private:
    int petals;
    float height;

    protected:

    public:
        void setPetals(int a){
            petals = a;
        }

        void setHeight(float a){
            height = a;
        }

        int getPetals(){
            return petals;
        }

        float getHeight(){
            return height;
        }

        void Bloom() override {
            cout << "Полевой цветок скудно цветёт..\n";
        }

        void Reproduction() override {
            cout << "Полевой цветок размножается самостоятельно..\n";
        }

        void DisplayType() override {
            cout << "Полевой цветок";
        }

        void Pollinators(){
            cout << "Полевой цветок опыляют шмели, бабочки, пчёлы..\n";
        }

        void Habitat(){
            cout << "Полевой цветок растёт в поле..\n";
        }
};