#include "Mlecz.h"
#include "../swiat/Swiat.h"
Mlecz::Mlecz(Swiat* swiat, Rng& rng, int x, int y) : Roslina(swiat, rng, x, y, TypOrganizmu::Mlecz, 0) { }

void Mlecz::akcja(){
	setWiek(getWiek() - 2);  //co ture wiek zwiekszal sie o 3
	for (int i=0;3>i;i++)
	Roslina::akcja();
}
