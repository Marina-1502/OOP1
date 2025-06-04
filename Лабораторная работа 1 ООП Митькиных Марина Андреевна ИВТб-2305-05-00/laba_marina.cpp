#include <iostream>
#include "Flower.h"
#include "Home.h"
#include "Field.h"
using namespace std;

void showActionsMenu(Flower* flower) {
    int action;
    do {
        cout << "\n�롥�� ����⢨�:\n";
        cout << "1. �������� �ࠪ���⨪�\n";
        cout << "2. ������\n";
        cout << "3. ���ᨭ⥧\n";
        cout << "4. �����\n";
        cout << "5. ������������\n";
        
        if (dynamic_cast<Home*>(flower)) {
            cout << "6. ���᪠���� �����\n";
            cout << "7. �������� ��诮\n";
        } else if (dynamic_cast<Field*>(flower)) {
            cout << "6. �ਢ���� ��뫨⥫��\n";
            cout << "7. �������� �।� ���⠭��\n";
        }
        
        cout << "0. �����\n> ";
        cin >> action;

        switch(action) {
            case 1: {
                cout << "\n��ࠪ���⨪�:\n";
                cout << "��୨: " << flower->getRoots() << endl;
                cout << "�த����⥫쭮��� �����: " << flower->getLifeDuration() << endl;
                
                if (auto home = dynamic_cast<Home*>(flower)) {
                    cout << "���: ����譨�\n";
                    cout << "�������楢: " << home->getOwnerCount() << endl;
                    cout << "������: " << home->getSize() << endl;
                } else if (auto field = dynamic_cast<Field*>(flower)) {
                    cout << "���: �������\n";
                    cout << "�����⪮�: " << field->getPetals() << endl;
                    cout << "����: " << field->getHeight() << endl;
                }
                break;
            }
            case 2: flower->Smell(); break;
            case 3: flower->Photosynthesis(); break;
            case 4: flower->Bloom(); break;
            case 5: flower->Reproduction(); break;
            case 6: {
                if (auto home = dynamic_cast<Home*>(flower)) home->Owner();
                else if (auto field = dynamic_cast<Field*>(flower)) field->Pollinators();
                break;
            }
            case 7: {
                if (auto home = dynamic_cast<Home*>(flower)) home->Cashpo();
                else if (auto field = dynamic_cast<Field*>(flower)) field->Habitat();
                break;
            }
            case 0: break;
            default: cout << "������ �롮�!\n";
        }
    } while(action != 0);
}

int main() {
    Flower** flowers = nullptr;
    int count = 0;
    int capacity = 0;
    int choice;
    
    do {
        cout << "\n����:\n";
        cout << "1. ������� ����譨� 梥⮪\n";
        cout << "2. ������� ������� 梥⮪\n";
        cout << "3. �������� �� 梥��\n";
        cout << "4. ������� 梥⮪\n";
        cout << "5. ����⢨� � 梥⪮�\n";
        cout << "6. ��室\n> ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                if(count >= capacity) {
                    int new_capacity = capacity + 5;
                    Flower** new_flowers = new Flower*[new_capacity];
                    for(int i = 0; i < count; ++i) {
                        new_flowers[i] = flowers[i];
                    }
                    delete[] flowers;
                    flowers = new_flowers;
                    capacity = new_capacity;
                }
                
                flowers[count] = new Home();
                cout << "������⢮ �������楢: "; 
                int owners; cin >> owners;
                ((Home*)flowers[count])->setOwner(owners);
                
                cout << "������: ";
                float size; cin >> size;
                ((Home*)flowers[count])->setSize(size);
                
                cout << "�த����⥫쭮��� �����: ";
                float life; cin >> life;
                flowers[count]->setLifeDuration(life);
                
                count++;
                cout << "����譨� 梥⮪ ᮧ���!\n";
                break;
            }
            case 2: {
                if(count >= capacity) {
                    int new_capacity = capacity + 5;
                    Flower** new_flowers = new Flower*[new_capacity];
                    for(int i = 0; i < count; ++i) {
                        new_flowers[i] = flowers[i];
                    }
                    delete[] flowers;
                    flowers = new_flowers;
                    capacity = new_capacity;
                }
                
                flowers[count] = new Field();
                cout << "������⢮ �����⪮�: ";
                int petals; cin >> petals;
                ((Field*)flowers[count])->setPetals(petals);
                
                cout << "����: ";
                float height; cin >> height;
                ((Field*)flowers[count])->setHeight(height);
                
                cout << "�த����⥫쭮��� �����: ";
                float life; cin >> life;
                flowers[count]->setLifeDuration(life);
                
                count++;
                cout << "������� 梥⮪ ᮧ���!\n";
                break;
            }
            case 3: {
                if(count == 0) {
                    cout << "��� 梥⮢ � ������樨.\n";
                    break;
                }
                cout << "\n���᮪ ��� 梥⮢:\n";
                for(int i = 0; i < count; ++i) {
                    cout << i + 1 << ". ";
                    flowers[i]->DisplayType();
                    cout << endl;
                }
                break;
            }
            case 4: {
                if(count == 0) {
                    cout << "��� 梥⮢ ��� 㤠�����.\n";
                    break;
                }
                cout << "\n���᮪ ��� 梥⮢:\n";
                for(int i = 0; i < count; ++i) {
                    cout << i + 1 << ". ";
                    flowers[i]->DisplayType();
                    cout << endl;
                }
                cout << "������ ����� 梥⪠ ��� 㤠�����: ";
                int index;
                cin >> index;
                index--;
                
                if(index >= 0 && index < count) {
                    delete flowers[index];
                    for(int i = index; i < count - 1; ++i) {
                        flowers[i] = flowers[i + 1];
                    }
                    count--;
                    cout << "���⮪ 㤠��.\n";
                } else {
                    cout << "������ �����!\n";
                }
                break;
            }
            case 5: {
                if(count == 0) {
                    cout << "���砫� ᮧ���� 梥⮪!\n";
                    break;
                }
                cout << "\n���᮪ ��� 梥⮢:\n";
                for(int i = 0; i < count; ++i) {
                    cout << i + 1 << ". ";
                    flowers[i]->DisplayType();
                    cout << endl;
                }
                cout << "�롥�� 梥⮪: ";
                int index;
                cin >> index;
                index--;
                
                if(index >= 0 && index < count) {
                    showActionsMenu(flowers[index]);
                } else {
                    cout << "������ �����!\n";
                }
                break;
            }
            case 6: {
                for(int i = 0; i < count; ++i) {
                    delete flowers[i];
                }
                delete[] flowers;
                cout << "��室\n";
                break;
            }
            default:
                cout << "������ �롮�!\n";
        }
    } while(choice != 6);
    
    return 0;
}