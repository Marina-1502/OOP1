#include <iostream>
#include "Flower.h"
#include "Home.h"
#include "Field.h"
using namespace std;

void showActionsMenu(Flower* flower) {
    int action;
    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Показать характеристики\n";
        cout << "2. Пахнуть\n";
        cout << "3. Фотосинтез\n";
        cout << "4. Цвести\n";
        cout << "5. Размножаться\n";
        
        if (dynamic_cast<Home*>(flower)) {
            cout << "6. Рассказать историю\n";
            cout << "7. Показать кашпо\n";
        } else if (dynamic_cast<Field*>(flower)) {
            cout << "6. Привлечь опылителей\n";
            cout << "7. Показать среду обитания\n";
        }
        
        cout << "0. Назад\n> ";
        cin >> action;

        switch(action) {
            case 1: {
                cout << "\nХарактеристики:\n";
                cout << "Корни: " << flower->getRoots() << endl;
                cout << "Продолжительность жизни: " << flower->getLifeDuration() << endl;
                
                if (auto home = dynamic_cast<Home*>(flower)) {
                    cout << "Тип: Домашний\n";
                    cout << "Владельцев: " << home->getOwnerCount() << endl;
                    cout << "Размер: " << home->getSize() << endl;
                } else if (auto field = dynamic_cast<Field*>(flower)) {
                    cout << "Тип: Полевой\n";
                    cout << "Лепестков: " << field->getPetals() << endl;
                    cout << "Высота: " << field->getHeight() << endl;
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
            default: cout << "Неверный выбор!\n";
        }
    } while(action != 0);
}

int main() {
    Flower** flowers = nullptr;
    int count = 0;
    int capacity = 0;
    int choice;
    
    do {
        cout << "\nМеню:\n";
        cout << "1. Создать домашний цветок\n";
        cout << "2. Создать полевой цветок\n";
        cout << "3. Показать все цветы\n";
        cout << "4. Удалить цветок\n";
        cout << "5. Действия с цветком\n";
        cout << "6. Выход\n> ";
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
                cout << "Количество владельцев: "; 
                int owners; cin >> owners;
                ((Home*)flowers[count])->setOwner(owners);
                
                cout << "Размер: ";
                float size; cin >> size;
                ((Home*)flowers[count])->setSize(size);
                
                cout << "Продолжительность жизни: ";
                float life; cin >> life;
                flowers[count]->setLifeDuration(life);
                
                count++;
                cout << "Домашний цветок создан!\n";
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
                cout << "Количество лепестков: ";
                int petals; cin >> petals;
                ((Field*)flowers[count])->setPetals(petals);
                
                cout << "Высота: ";
                float height; cin >> height;
                ((Field*)flowers[count])->setHeight(height);
                
                cout << "Продолжительность жизни: ";
                float life; cin >> life;
                flowers[count]->setLifeDuration(life);
                
                count++;
                cout << "Полевой цветок создан!\n";
                break;
            }
            case 3: {
                if(count == 0) {
                    cout << "Нет цветов в коллекции.\n";
                    break;
                }
                cout << "\nСписок всех цветов:\n";
                for(int i = 0; i < count; ++i) {
                    cout << i + 1 << ". ";
                    flowers[i]->DisplayType();
                    cout << endl;
                }
                break;
            }
            case 4: {
                if(count == 0) {
                    cout << "Нет цветов для удаления.\n";
                    break;
                }
                cout << "\nСписок всех цветов:\n";
                for(int i = 0; i < count; ++i) {
                    cout << i + 1 << ". ";
                    flowers[i]->DisplayType();
                    cout << endl;
                }
                cout << "Введите номер цветка для удаления: ";
                int index;
                cin >> index;
                index--;
                
                if(index >= 0 && index < count) {
                    delete flowers[index];
                    for(int i = index; i < count - 1; ++i) {
                        flowers[i] = flowers[i + 1];
                    }
                    count--;
                    cout << "Цветок удалён.\n";
                } else {
                    cout << "Неверный номер!\n";
                }
                break;
            }
            case 5: {
                if(count == 0) {
                    cout << "Сначала создайте цветок!\n";
                    break;
                }
                cout << "\nСписок всех цветов:\n";
                for(int i = 0; i < count; ++i) {
                    cout << i + 1 << ". ";
                    flowers[i]->DisplayType();
                    cout << endl;
                }
                cout << "Выберите цветок: ";
                int index;
                cin >> index;
                index--;
                
                if(index >= 0 && index < count) {
                    showActionsMenu(flowers[index]);
                } else {
                    cout << "Неверный номер!\n";
                }
                break;
            }
            case 6: {
                for(int i = 0; i < count; ++i) {
                    delete flowers[i];
                }
                delete[] flowers;
                cout << "Выход\n";
                break;
            }
            default:
                cout << "Неверный выбор!\n";
        }
    } while(choice != 6);
    
    return 0;
}