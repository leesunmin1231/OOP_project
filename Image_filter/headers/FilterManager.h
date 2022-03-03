#ifndef FilterManager_h
#define FilterManager_h

#include <sstream>
#include <vector>
#include "CustomFilter.h"

class FilterManager {
private:
    std::vector<CustomFilter> custom;
    void showbasiclist();
    void showcustomlist();
    void create_custom();
    void show_custom();
    void Edit_custom();
    void Delete_custom();
    void save();

public:
    FilterManager();
    void run();
    std::vector<CustomFilter> getcustom() { return this->custom; }
    // ������ ȣ���ϸ� ���Ͽ��� Ŀ���� ���� ���� �����ͼ� ���Ϳ� �����ϱ�.
};

#endif /* FilterManager_h */