//
//  box.cpp
//  sample
//
//  Created by Kohei Doi on 2020/10/14.
//

#include "box.hpp"

/*
 * --ボックスの描画関数----------------------------------------------------------------------
 *
 *     原点中心に幅width, 高さheight, 奥行きlengthのボックスを描画
 *  一番最後は描画のタイプを指定。何も指定しない場合、自動で「GL_LINE_LOOP」
 * -----------------------------------------------------------------------------------------
 */
void makebox(double width, double height, double length, GLenum type)
{
    double box[8][3];    //頂点データ格納用配列

    //頂点データの格納
    box[0][0] = -width/2;    box[0][1] =  height/2;    box[0][2] = length/2;
    box[1][0] = -width/2;    box[1][1] = -height/2;    box[1][2] = length/2;
    box[2][0] =  width/2;    box[2][1] = -height/2;    box[2][2] = length/2;
    box[3][0] =  width/2;    box[3][1] =  height/2;    box[3][2] = length/2;
    
    box[4][0] = -width/2;    box[4][1] =  height/2;    box[4][2] = -length/2;
    box[5][0] = -width/2;    box[5][1] = -height/2;    box[5][2] = -length/2;
    box[6][0] =  width/2;    box[6][1] = -height/2;    box[6][2] = -length/2;
    box[7][0] =  width/2;    box[7][1] =  height/2;    box[7][2] = -length/2;

    //前面描画・黄
    glColor3d(1.0, 1.0, 0.0);
    glNormal3d(0.0, 0.0, 1.0);
    glBegin(type);
        glVertex3dv(box[0]);
        glVertex3dv(box[1]);
        glVertex3dv(box[2]);
        glVertex3dv(box[3]);
    glEnd();

    //後面描画・赤
    glColor3d(1.0, 0.0, 0.0);
    glNormal3d(0.0, 0.0, -1.0);
    glBegin(type);
        glVertex3dv(box[4]);
        glVertex3dv(box[5]);
        glVertex3dv(box[6]);
        glVertex3dv(box[7]);
    glEnd();
    
    //上面描画・マゼンダ
    glColor3d(1.0, 0.0, 1.0);
    glNormal3d(0.0, 1.0, 0.0);
    glBegin(type);
        glVertex3dv(box[4]);
        glVertex3dv(box[0]);
        glVertex3dv(box[3]);
        glVertex3dv(box[7]);
    glEnd();

    //右面描画・緑
    glColor3d(0.0, 1.0, 0.0);
    glNormal3d(1.0, 0.0, 0.0);
    glBegin(type);
        glVertex3dv(box[3]);
        glVertex3dv(box[2]);
        glVertex3dv(box[6]);
        glVertex3dv(box[7]);
    glEnd();

    //左面描画・シアン
    glColor3d(0.0, 1.0, 1.0);
    glNormal3d(-1.0, 0.0, 0.0);
    glBegin(type);
        glVertex3dv(box[4]);
        glVertex3dv(box[5]);
        glVertex3dv(box[1]);
        glVertex3dv(box[0]);
    glEnd();
    
    //下面描画・青
    glColor3d(0.0, 0.0, 1.0);
    glNormal3d(0.0, -1.0, 0.0);
    glBegin(type);
        glVertex3dv(box[6]);
        glVertex3dv(box[5]);
        glVertex3dv(box[1]);
        glVertex3dv(box[2]);
    glEnd();
}
