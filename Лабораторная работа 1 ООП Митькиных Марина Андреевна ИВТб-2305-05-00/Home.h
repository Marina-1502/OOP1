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
            cout << "����譨� 梥⮪ ����쭮 梥���..\n";
        }

        void Reproduction() override {
            cout << "����譨� 梥⮪ ࠧ��������� � ������� ��..\n";
        }

        void DisplayType() override {
            cout << "����譨� 梥⮪";
        }

        void Owner(){
            cout << "���鶴 梥⪠ ��᪠�뢠�� � ��� ���ਨ..\n";
        }

        void Cashpo(){
            cout << "� ����譥�� 梥⪠ ��ᨢ�� ��诮.\n";
        }
};