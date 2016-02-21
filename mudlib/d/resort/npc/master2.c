 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave(); 
void create()
{
    set_name("ѩ���", ({ "master xuerui", "master","xuerui" }) );
    set("class","legend");      
    set("gender", "Ů��" );
    set("nickname", HIG "���齣��"NOR);
    set("reward_npc", 1);
    set("difficulty", 35);
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",40);
    set("str",100);
   set("ill_boss",5);
    
    set("apprentice_available", 50);
    create_family("��ѩɽׯ", 1, "ׯ������");
    set("rank_nogen",1);
    set("ranks",({"��ͯ","С��","����","����","����",WHT"����"NOR,WHT"��ʥ"NOR,HIW"����"NOR}));
    set("long",
        "ѩ�����ʮ���꿪ʼ�ͺͰ��������������������˵����ϱڣ�\n"
        "�����޵С���������������ʢ֮ʱ���ֺ�Ȼ�˳������������ڴˡ�\n");
    set("inquiry", ([
        "leave" : (: leave :),
                ]));    
    set("fly_target",1);
    set("force_factor", 100);
    set("max_atman", 300);
    set("atman", 300);
    set("max_force", 1500);
    set("force", 1500);
    set("max_mana", 300);
    set("mana", 300); 
    set("combat_exp", 9999999);
    set("score", 90000);
    set_skill("unarmed", 100);
    set_skill("sword", 200);
    set_skill("force", 140);
    set_skill("parry", 100);
    set_skill("literate", 180);
    set_skill("dodge", 150);
    set_skill("perception", 220);
    set_skill("move",150);
    set_skill("blade",150);
    set_skill("shortsong-blade",100);
    set_skill("six-sense",200); 
    set_skill("meihua-shou", 180);
    set_skill("diesword",180);
    set_skill("qidaoforce", 140);
    set_skill("fall-steps", 180);
    
    map_skill("perception","six-sense");
    map_skill("unarmed", "meihua-shou");
    map_skill("sword","diesword");
    map_skill("force", "qidaoforce");
    map_skill("parry", "diesword");
    map_skill("dodge", "fall-steps"); 
    set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "sword.caidiekuangwu" :),
        }) );  
    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/msword")->wield();
}
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say ��ׯ�������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
    }
}
void do_recruit(object ob)
{
    if( (string)ob->query("gender") != "Ů��" )
    {      command("say ��ֻ��Ů���ӣ��㻹��ȥ���ҵ����Ӱɣ�");
    }
    else { 
        command("smile");
        command("say ���պ���д�ɣ�");
        command("smile");
        command("recruit " + ob->query("id") );
    }
}
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "legend");
    add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
    object xiaocui;
    if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    {
        command("smile");
        command("say ������С�����ɡ�");
        return 0;
    }
    else
        command("sigh");
    command("ѩ��������ĴӴ������վ���������������е���ɰ����");
    command("wield wangsword");
    command("say �룡");
    remove_call_out("do_unwie");
    call_out("do_unwie", 3);
    return 1;
} 
int do_unwie()
{
    if( !this_object()->is_fighting()) 
    {   
//      command("unwield wangsword");
        message_vision("$N����豭ǳ�һ�ڣ�������������������һ�ۣ�����������ϡ�\n", this_object());
        command("smile");
        return 1;
    }
    else
        call_out("do_unwie", 3);
}  
int do_killing(string arg)
{
    object player, victim, weapon;
    string name, id, id_class;
    if(!arg) return 0;
    player = this_player();
    if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
    {
        name = victim->name();
        if( name == "����")
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ�����ݼ����������С�\n", this_object());
                weapon->wield();
            }
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        if( name == "ѩ���")
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ�����ݼ����������С�\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "legend"&& userp(victim)&&player!=victim)
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ�����ݼ����������С�\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            message_vision("$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
        
        return 0;
    }
    return 0;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int leave() {
        if (this_player()->query("class")!="legend") return 0;
        message_vision(CYN"$N�����˸���־���Ҳ���ǿ�����¡�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵��ֻ�Ǿ����ķ��ǵ��Ӳ���ʹ�ã������������ľ�������Ҳ��᲻���ˡ�\n"NOR,this_object(),this_player());
        return 1;
} 