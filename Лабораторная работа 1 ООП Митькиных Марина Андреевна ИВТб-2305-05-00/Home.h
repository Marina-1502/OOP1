#include <iostream>
using namespace std;

class Home : public Flower{
    private:
    int owner_count;
    float size;

    protected:

    public:
        Home():owner_count(0), size(0){};

        void setOwner(int a){
            owner_count = a;
        }

        void setSize(float a){
            size = a;
        }

        int getOwnerCount(){
            return owner_count;
        }

        float getSize(){
            return size;
        }

        void Bloom() override {
            cout << "Домашний цветок обильно цветёт..\n";
        }

        void Reproduction() override {
            cout << "Домашний цветок размножается с помощью людей..\n";
        }

        void DisplayType() override {
            cout << "Домашний цветок";
        }

        void Owner(){
            cout << "Хозяин цветка рассказывает о его истории..\n";
        }

        void Cashpo(){
            cout << "У домашнего цветка красивое кашпо.\n";
        }
};