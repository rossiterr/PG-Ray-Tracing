#include "Renderer.cpp"

#define PI 3.1415926535f

using namespace std;

// definição da câmera
float d = 1000.0f;
int Hy = d;
int Hx = d;
Vec3 camPos(0, 0, 0);
Vec3 camDir(1, 0, 0);
Vec3 vUp = Vec3(1, 0, 1);
Camera camera(camPos, camDir, vUp, d, Hy, Hx);

// definição da cena
Cena cena(Cor(100, 100, 100));

// definição das luzes
Luz l1 = Luz(Vec3(800, 400, 100), Cor(255, 255, 255));
Luz l2 = Luz(Vec3(500, -400, 100), Cor(255, 255, 255));

// definição dos objetos
Esfera *e1 = new Esfera(0.1f, 0.0f, 0.0f, 0.1f, 0.9f, 3, 1.5f,
                        Vec3(1100, 0, 0), 300, Cor(0, 0, 255));
Esfera *e2 = new Esfera(0.6f, 0.6f, 0.3f, 0.0f, 0, 3, 0,
                        Vec3(600, 500, 500), 100, Cor(50, 255, 50));
Esfera *e3 = new Esfera(0.6f, 0.6f, 0.3f, 0.0f, 0, 3, 0,
                        camPos, 100, Cor(100, 0, 255));

Plano *p1 = new Plano(0.5f, 0.5f, 0.1f, 0.3f, 0.0f, 1, 0,
                      Vec3(0, 0, -400), Vec3(0, 0, 1), Cor(255, 255, 0));
Plano *p2 = new Plano(0.5f, 0.5f, 0.1f, 0.3f, 0.0f, 2, 0,
                      Vec3(1100, -400, 0), Vec3(0, 1, 1), Cor(100, 0, 255));

Triangulo *t1 = new Triangulo(0.1f, 0.2f, 0.0f, 0.8f, 0.0f, 3, 1.5f,
                              vector<Vec3>{
                                  Vec3(855, 350, -200),
                                  Vec3(1100, 600, 200),
                                  Vec3(550, 690, -130)},
                              Cor(0, 255, 0));

Forma *f1 = dynamic_cast<Forma *>(e1);
Forma *f2 = dynamic_cast<Forma *>(e2);
Forma *f3 = dynamic_cast<Forma *>(p1);
Forma *f4 = dynamic_cast<Forma *>(p2);
Forma *f5 = dynamic_cast<Forma *>(t1);

int pixelsX = 1000;
int pixelsY = 1000;

int main()
{
    // inicialização da cena
    cena.addLuz(l1);
    // cena.addLuz(l2);
    cena.addForma(f1);
    cena.addForma(f2);
    cena.addForma(f3);
    cena.addForma(f4);
    cena.addForma(f5);

    render(pixelsX, pixelsY, cena, camera, "antes");

    // e1->translate(-100, 200, 200);

    // p1->rotate(Vec3(1, 0, 0), PI / 6);
    // p2->rotate(Vec3(1, 0, 1), PI / 6);

    t1->translate(0, 0, 200);
    t1->rotate(Vec3(0.5f, -1, 1), PI / 3);

    camera.translate(0, 450, 500);
    camera.rotate(Vec3(0, -1, 1), -PI / 6);
    // camera.scale(1.6f, 0.9f, 1);

    render(pixelsX, pixelsY, cena, camera, "depois");

    return 0;
}
