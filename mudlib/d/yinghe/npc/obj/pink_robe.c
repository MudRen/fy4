#include <armor.h>
#include <ansi.h>
inherit CLOTH; 
void create()
{
        set_name("轻红软袍", ({ "pink robe","robe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件淡淡的粉色轻袍，轻盈柔滑，如同雨中的桃花。
一条浅红的丝带恰到好处地环在腰间。\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 5);
        }
        ::init_cloth();
}     
