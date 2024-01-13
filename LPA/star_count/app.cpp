#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <queue>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

typedef struct BOX
{
    Point p1, p2;
} BOX;


// Primeiro eu vou binarizar a imagem
void binaryImg(Mat img, int thasholder){

    for(int y=0; y < img.rows; y++){

        for(int x=0; x < img.cols; x++){

            if( img.at<uchar>(y,x) >= thasholder ){
                img.at<uchar>(y,x) = 255;
            }else{
                img.at<uchar>(y,x) = 0;
            }

        }

    }

}

bool isOut(Mat img, int y, int x){
    if (x < 0 || x >= img.cols || y < 0 || y >= img.rows) return true;
    else return false;
}

BOX* createBoundBox(Mat img, Point point){

    queue<Point> fila;
    fila.push(point);

    int max_x = point.x;
    int min_x = point.x;

    int max_y = point.y;
    int min_y = point.y;

    do{

        Point n_p = fila.front();
        fila.pop();

        if( max_x < n_p.x) max_x = n_p.x;
        if( min_x > n_p.x) min_x = n_p.x;
        if( max_y < n_p.y) max_y = n_p.y;
        if( min_y > n_p.y) min_y = n_p.y;

        img.at<uchar>(n_p.y,n_p.x) = 0;

        if(!isOut(img,n_p.y, n_p.x+1) && img.at<uchar>(n_p.y, n_p.x+1) == 255){
            fila.push(Point(n_p.x+1, n_p.y));
        }

        if(!isOut(img,n_p.y, n_p.x-1) && img.at<uchar>(n_p.y, n_p.x-1) == 255){
            fila.push(Point(n_p.x-1, n_p.y));
        }

        if(!isOut(img,n_p.y+1, n_p.x) && img.at<uchar>(n_p.y+1, n_p.x) == 255){
            fila.push(Point(n_p.x, n_p.y+1));
        }
        
        if(!isOut(img, n_p.y-1, n_p.x) && img.at<uchar>(n_p.y-1, n_p.x) == 255){
            fila.push(Point(n_p.x, n_p.y-1));
        }

    }while(!fila.empty());

    BOX* box = (BOX*) malloc(sizeof(BOX));
    box->p1 = Point(min_x,min_y);
    box->p2 = Point(max_x,max_y);
    
    return box;

}

vector<BOX*> findContours(Mat img){

    vector<BOX*> allBoxs;
    int cont = 0;

    for(int y=0; y<img.rows; y++) {
        for (int x=0; x<img.cols; x++) {
            uchar pixel = img.at<uchar>(y,x);

            if(pixel == 255){

                if(cont >= 20000) return allBoxs;
                cont++;

                BOX* tmp = createBoundBox(img, Point(x,y));
                allBoxs.push_back(tmp);
            }
        }
        
    }

    return allBoxs;

}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Sintaxe: %s <nome-arquivo-png>\n", argv[0]);
        return 1;
    }

    // Abre a imagem, passada pela linha de comando, em modo escala-de-cinza
    Mat img = imread(argv[1], IMREAD_GRAYSCALE);


    int thashholder = 80;

    binaryImg(img, thashholder);

    imwrite("img_binary.png", img);

    vector<BOX*> allStart = findContours(img);
    int tamanho = allStart.size();
    cout << "Total de estrelas: " << tamanho << "\n";

    Mat imgOriginal = imread(argv[1], IMREAD_COLOR);

    BOX* box;

    for(int i=0; i < tamanho; i++){

        box = allStart.at(i);

        rectangle(imgOriginal, box->p1, box->p2, Scalar(0, 255, 0), 1);

    }

    imwrite("output-starts-rect.png", imgOriginal);

    

}