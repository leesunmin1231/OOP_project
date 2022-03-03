#ifndef CustomFilter_h
#define CustomFilter_h
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include"Image.h"
#include"Filter.h"


class CustomFilter :Filter {
private:
    std::string filtername;
    int brightness; // ���
    double contrast; // ���
    int inversion; // ä��
    int blurring; // ����
    int sharpness; // �׸���
    cv::Mat result; // ������ �̹���

public:
    CustomFilter();
    CustomFilter(std::string filtername,
        int brightness, // ���
        double contrast, // ���
        int inversion, // �¿� ����, ���� ����
        int blurring, // �帮��
        int sharpness); // �����ϰ�
    void apply(Image* image);


    // getter, setter
    std::string getFilterName(); // ���� �̸� ��ȯ
    int getbrightness();
    double getcontrast();
    int getinversion();
    int getblurring();
    int getsharpness();
    cv::Mat getresult();
    void setFilterName(std::string newname);
    void setbrightness(int a);
    void setcontrast(double b);
    void setinversion(int c);
    void setblurring(int d);
    void setsharpness(int f);
};

#endif /* CustomFilter_h */