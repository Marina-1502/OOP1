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
            cout << "������� 梥⮪ �㤭� 梥���..\n";
        }

        void Reproduction() override {
            cout << "������� 梥⮪ ࠧ��������� ᠬ����⥫쭮..\n";
        }

        void DisplayType() override {
            cout << "������� 梥⮪";
        }

        void Pollinators(){
            cout << "������� 梥⮪ ������ 謥��, ����窨, ����..\n";
        }

        void Habitat(){
            cout << "������� 梥⮪ ����� � ����..\n";
        }
};