 inherit NPC;
void create()
{
        set_name("满脸风霜的老人", ({ "oldman", "old man", "man" }) );
        set("gender", "男性");
        set("age", 74);
        set("long",
"这是一个满脸风霜的老人，但他双目有神，太阳穴高高隆起！\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 2000000);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
                "满脸风霜的老人用袖子远远地一拂，你立刻感到透不过气来。\n",
        }) );
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 60); 
        
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 200);
        set_skill("move", 150);
        set_skill("doomforce", 50);
        set_skill("doomstrike", 110);
        set_skill("doomsteps", 110);
        
        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hantian" :),
        }) ); 
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
