#ifndef Camera_h
#define Camera_h

#include "Intersecoes.cpp"

using namespace std;

struct Camera
{
    Vec3 posicao;
    Vec3 mira;
    Vec3 Vup;
    Vec3 W;  // mesma direcao que (M − C), mas sentido oposto;
    Vec3 U;  // vetor horizontal (esquerda) paralelo à tela
    Vec3 V;  // vetor vertical (cima) paralelo à tela
    float d; // distância até a tela
    float altura;
    float largura;

    Camera();
    Camera(const Vec3 &C, const Vec3 &M,
           const Vec3 &Vup,
           float d, float altura, float largura);

    virtual ~Camera();
};

#endif