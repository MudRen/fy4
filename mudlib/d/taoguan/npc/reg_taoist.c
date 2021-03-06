 inherit NPC;
void create()
{
        set_name("道士", ({ "taoist" }) );
        set("gender", "男性");
        set("age", 32);
        set("long","三清宫的道士，着一身黑色的道袍。\n");
        set("combat_exp", 10000+random(5000));
        set("score", 200); 
        set("class", "taoist");
        set("int", 30);
        set("cps", 30);
        set("spi", 30); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "谷衣心法": "谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) ); 
        create_family("三清宫", 7, "弟子"); 
        set_skill("literate", 40);
        set_skill("magic", 20);
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50); 
        map_skill("force", "gouyee"); 
        set_skill("taoism", 30);
        set_skill("necromancy", 30);     
        map_skill("spells", "necromancy"); 
        set_temp("apply/dodge", 25);
        set_temp("apply/armor", 25); 
        setup(); 
        add_money("coin", 10);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear(); 
}      
