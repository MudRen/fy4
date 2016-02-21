 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
int give_jade();
void create()
{
        set_name("����ͷ", ({ "gao oldman" }) );
        set("gender", "����" );
        set("age", 45);
        set("title","��������");
        set("long",
                "һ��������͵����˼ң�Ц�ݴ��飬������˪��
���ƺ�������ܾ��ˣ�������������������Ϥ��\n");
        set("force_factor", 100);
        set("combat_exp", 100000+random(10000000));
        set("attitude", "friendly");

        set_skill("force",100);
        set_skill("dodge",120);
        set_skill("perception",160);        
        set_skill("jingyiforce",200);        
        set_skill("blade",180);
        set_skill("springrain-blade",160);
        set_skill("chaos-steps",120);
        map_skill("force","jingyiforce");
        map_skill("dodge","chaos-steps");
        map_skill("blade","springrain-blade");

        set("chat_chance", 1);
        set("chat_msg", ({
                "����ͷ����üͷ������ʢҩ��ҩ�������ˣ�������찡��������\n"
                    }));
        set("skill_public", 1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        	                (: wieldblade  :),
        }) );
        set("inquiry", ([
                "�����޼���" : (: give_jade :),
        ]));
        setup();
        //carry_object(__DIR__"obj/birdbox");
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear(); 
} 

int accept_object(object me, object ob){
        if (ob->query("name") == "�ڴ�ҩ��" && ob->query("id") == "medvase" && !me->query("free_rain/med"))
		{
                message_vision("$N����üͷ���ӹ�"+ob->query("name")+"������л��л����������ʡ���Ҳ����鷳�ˡ���\n", this_object());
                message_vision("$N��Ȼ��������ͷ������ѽ������ҩ����ɽѩ����û�һ�����������أ���\n", this_object());        
                me->set("free_rain/med", 1);
                return 1;
		}

        if (ob->query("name") == HIC"��ɽѩ��"NOR && ob->query("id") == "snow lotus" && me->query("free_rain/med") && !me->query("free_rain/lotus"))
		{
                        message_vision("$N�ӹ�"+ob->query("name")+"��ϸһ������������ԶԶԣ�������������ˣ���ȱ���ΰ���ҩ�����ˡ���\n", this_object());
						me->set("free_rain/lotus", 1);
                return 1;
		}

		if (ob->query("name") == "�ΰ�" && ob->query("id") == "salt rock" && me->query("free_rain/lotus") && !me->query("free_rain/ending"))
		{
                		message_vision(CYN"$N������Ц�����첻�������ˣ����Ȼ����Ҫ�ҵ��ˡ�ΪѰ�������Ҵ��ָ����һ������\n\n"NOR, this_object());

                        me->set("free_rain/ending",1);
                        me->add("combat_exp",20000);
						me->add("potential",1000);
						me->add("score",500);
                        tell_object(me,"�㱻�����ˣ�\n" + chinese_number(1000) + "��ʵս����\n"
                        + chinese_number(200) + "��Ǳ��\n" + chinese_number(500)+"���ۺ�����\n");
						return 1;
		}
        return 0;

} 
int recognize_apprentice(object ob){
    if(ob->query("free_rain/ending")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$N���������ӣ���ֻ����ɽѩ��������������������������\n", 
                        this_object());
        else 
        message_vision("$N������$n��򣺡���֪���ᣬ��ʱ��һ��ҩ����Ҫҩ���ӵģ������ΰ�֮�ࡣ��\n", 
                        this_object(), ob);             
                return 0;
    }
} 

int give_jade()
{
        object obj;
if( !query("given"))
        {
message_vision(CYN"$N��̾����������󱲾�ȻҲ֪������£�����������Ȼ��������\n�������п鵱�������µļ����С�ı��棬��Ҫ�ü��ҵ��˿����ˡ���\n"+"$N�ݸ�$nһ��"+GRN"�޼���������"NOR+"��\n", this_object(),this_player());
obj = new(__DIR__"obj/jade");
obj->move(this_player());
set("given",1);
        }
else
command("say ����󱲾�ȻҲ֪������£���ϧ�����޼����������ջƻ�������\n");
        return 1;
} 
int wieldblade()
{
command("sigh");
perform_action("blade.dangshimingyue");
command("grin");
return 1;
}