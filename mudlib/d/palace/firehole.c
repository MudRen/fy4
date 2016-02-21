 // Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "���");
        set("long", @LONG
���붴��(hole)���;���һ������(air)����������붴Խ����ܿ���Խ�ȣ�
���������ߡ��㲻���������£�תĿ������ֻ������ɽ��(rock)�����Ա�����
����֮ɫ���·���ʱ���л���ӿ����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"interroad",
])); 
        set("outdoors", "palace");
        set("objects", ([
        __DIR__"npc/wolfman" : 1,
                        ]) );
        set("coor/x",180);
        set("coor/y",-50);
        set("coor/z",20);
        setup();
} 
void init()
{       object ob;
        if( interactive( ob = this_player()))
        remove_call_out("arrowing");
        call_out("arrowing", random(10)+5, ob);
} 
int arrowing(object ob) 
{
        int i;
        int damage;
        if(ob)
        if( environment(ob) == this_object())
        {
        message_vision(HIR"һ�ɳ��ȵ������γ�һ���������$N�����������\n", ob);
        message_vision("$N�����ȵ�������ý�ͷ�ö����һϢ��\n"NOR, ob);
   i = (int)ob->query("eff_kee");
        damage = random(20)+25  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if (ob->is_zombie()) ob->die();
        if( environment(ob) == this_object())
        call_out("arrowing",5, ob);     
        }
        else 
        return 1;
}     