#include <iostream>
using namespace std;

class Flower {
    private:
    int roots;
    float life_duration;

    protected:

    public:
        Flower(){
            roots = 0;
            life_duration = 0;
        }
        virtual ~Flower() {}

        void setRoots(int a){
            roots = a;
        }

        void setLifeDuration(float a){
            life_duration = a;
        }

        int getRoots(){
            return roots;
        }

        float getLifeDuration(){
            return life_duration;
        }

        void Smell(){
            cout << "���⮪ ���᭮ ��孥�.\n";
        }

        void Photosynthesis(){
            cout << "�ந�室�� ��ᨭ⥧..\n";
        }

        virtual void Bloom() = 0;
        virtual void Reproduction() = 0;
        virtual void DisplayType() = 0;
};