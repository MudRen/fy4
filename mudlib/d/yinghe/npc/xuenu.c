#include <ansi.h>
#include <combat.h> 
inherit NPC; 
void smart_fight();
object offensive_target(object me);
void create()
{
        set_name(HIR"血奴"NOR, ({ "xue nu" }) );
        set("gender", "女性" );
    set("age", 18);
        set("int", 65);
        set("per", 30);
        set("str", 30);
        set("fle", 50);
        set("dur", 42);
        set("cor", 60);
        set("agi",80);
    set("long",
"从未见过的美丽，也从未见过的怪异。她并不是赤裸着的。她还穿着一半衣裳
--既不是上面一半，也不是下面一半。她右边半身衣裳，穿得很整齐，左边半
身却是赤裸的。她在耳上戴着珠环，有半边脸上抹着脂粉，发上还有珠翠满头。
只有右边。她的左半身看来就像是个初生的婴儿。
\n"
                );
    set("force_factor", 120);
    set("max_force",9000);
        set("force",9000); 
    set("combat_exp", 10000000);
    set("score", -90000);
    set_skill("unarmed", 220);
    set_skill("throwing", 200);
    set_skill("force", 300);
    set_skill("parry", 450);
    set_skill("literate", 110);
        set_skill("dodge", 350);
        set_skill("demon-force", 250);
        set_skill("demon-strike",300);
        set_skill("demon-steps",200);
        
                
   map_skill("force", "demon-force");
        map_skill("unarmed","demon-strike");
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("throwing","tanzhi-shentong");
        set("chat_chance",3);
        set("chat_msg",({ 
                })      
        );
      
        setup();
//      carry_object(__DIR__"obj/grey_cloth")->wear();
//      carry_object(__DIR__"obj/owl_shoes")->wear();
//      carry_object(__DIR__"obj/fried_nuts")->wield();
        
}         
