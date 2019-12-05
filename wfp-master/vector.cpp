#include "Core/vector.h"

WFP_Vec2i::WFP_Vec2i()
 : x(), y(){

}
WFP_Vec2i::WFP_Vec2i(int x,int y)
 : x(x), y(y){

}
WFP_Vec3i::WFP_Vec3i()
 : x(), y(), z(){

}
WFP_Vec3i::WFP_Vec3i(int x,int y,int z)
 : x(x), y(y), z(z){

}
WFP_Vec4i::WFP_Vec4i()
 : x(), y(), w(), h(){

}
WFP_Vec4i::WFP_Vec4i(int x,int y,int w,int h)
 : x(x), y(y), w(w), h(h){

}
WFP_Vec4i::WFP_Vec4i(WFP_Vec2i& vec1, WFP_Vec2i& vec2)
 : x(vec1.x), y(vec1.y), w(vec2.x), h(vec2.y){

}
WFP_Vec4i::WFP_Vec4i(WFP_Vec3i& vec1, int a)
 : x(vec1.x), y(vec1.y), w(vec1.z), h(a){

}
WFP_Pos::WFP_Pos()
: WFP_Vec2i(){

}
WFP_Size::WFP_Size()
: WFP_Vec2i(){

}
WFP_Pos::WFP_Pos(int x,int y)
: WFP_Vec2i(x,y){

}
WFP_Size::WFP_Size(int x,int y)
: WFP_Vec2i(x,y){

}
