 // TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name("生铁块", ({ "shengkuai" }) );
    set_weight(50000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "块");
        set("long", "一块沉重发亮的生铁。\n");
    set("rigidity", 400);
        set("for_create_weapon",1);
        set("value", 20000);
        set("material", "heavyiron");
        set("base_damage",15);
    set("max_enchant",6);
    }
    
    ::init_hammer(15);
}  
