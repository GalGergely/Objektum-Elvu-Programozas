#include "novenyek.h"

void Novenyek::alfa()
{
    if(_fajta==Puffancs)
    {
        _nutrients=_nutrients+2;
        isAlive();
    }
    if(_fajta==Deltafa)
    {
        _nutrients=_nutrients-3;
        isAlive();
    }
    if(_fajta==Parabokor)
    {
        _nutrients=_nutrients+1;
        isAlive();
    }
}

void Novenyek::delta()
{
    if(_fajta==Puffancs)
    {
        _nutrients=_nutrients-2;
        isAlive();
    }
    if(_fajta==Deltafa)
    {
        _nutrients=_nutrients+4;
        isAlive();
    }
    if(_fajta==Parabokor)
    {
        _nutrients=_nutrients+1;
        isAlive();
    }
}

void Novenyek::nincs()
{
    if(_fajta==Puffancs)
    {
        _nutrients=_nutrients-1;
        isAlive();
    }
    if(_fajta==Deltafa)
    {
        _nutrients=_nutrients-1;
        isAlive();
    }
    if(_fajta==Parabokor)
    {
        _nutrients=_nutrients-1;
        isAlive();
    }
}