#include <iostream>
#include <fstream>
#include "field.h"
#include "units.h"
#include "engine.h"
using namespace std;

int main()
{
    string filename_ = "map.txt";
    string filename;
    cout << "�������ͼ����(�����·��)(������Ϊ�գ�ʹ��Ĭ��ֵmap.txt): \n";
    getline(cin, filename);
    ifstream ifs;
    ifs.open(filename.c_str());
    if (!ifs) {
        ifs.open(filename_);
    }
    if (!ifs) {
        cout << "Failed to open map.txt!" << endl;
        cout << "���������ַ��˳�" << endl;
        cin >> filename;
        return -1;
    }

    Field* f = loadMap(ifs);
    if (f == NULL) {
        cout << "Failed to load map!" << endl;
        return -1;
    }
    play(*f, cin, cout);

    delete f;
    ifs.close();
    cout << "��������ǿ��ַ��˳�" << endl;
    cin >> filename;
    return 0;
}

