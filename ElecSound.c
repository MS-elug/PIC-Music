#include "C:\Users\Raptor\Desktop\ElecSound\ElecSound.h"

#define PIN_BUZZER          PIN_B0

#DEFINE TEMPO 1000000

#DEFINE TEMPS_RONDE (4*TEMPO)
#DEFINE TEMPS_BLANCHE (2*TEMPO)
#DEFINE TEMPS_NOIRE TEMPO
#DEFINE TEMPS_CROCHE (TEMPO/2)
#DEFINE TEMPS_DOUBLE_CROCHE (TEMPO/4)

#DEFINE WAIT 2000

#DEFINE NOTE_DO0   30581
#DEFINE NOTE_DODIESE0   28860
#DEFINE NOTE_RE0   27241
#DEFINE NOTE_REDIESE0   25714
#DEFINE NOTE_MI0   24272
#DEFINE NOTE_FA0   22910
#DEFINE NOTE_FADIESE0   21622
#DEFINE NOTE_SOL0   20408
#DEFINE NOTE_SOLDIESE0   19264
#DEFINE NOTE_LA0   18182
#DEFINE NOTE_LADIESE0   17161
#DEFINE NOTE_SI0   16197
#DEFINE NOTE_DO1   15288
#DEFINE NOTE_DODIESE1   14430
#DEFINE NOTE_RE1   13620
#DEFINE NOTE_REDIESE1   12857
#DEFINE NOTE_MI1   12134
#DEFINE NOTE_FA1   11453
#DEFINE NOTE_FADIESE1   10811
#DEFINE NOTE_SOL1   10204
#DEFINE NOTE_SOLDIESE1   9631
#DEFINE NOTE_LA1   9091
#DEFINE NOTE_LADIESE1   8581
#DEFINE NOTE_SI1   8099
#DEFINE NOTE_DO2   7645
#DEFINE NOTE_DODIESE2   7216
#DEFINE NOTE_RE2   6811
#DEFINE NOTE_REDIESE2   6428
#DEFINE NOTE_MI2   6068
#DEFINE NOTE_FA2   5727
#DEFINE NOTE_FADIESE2   5405
#DEFINE NOTE_SOL2   5102
#DEFINE NOTE_SOLDIESE2   4816
#DEFINE NOTE_LA2   4545
#DEFINE NOTE_LADIESE2   4290
#DEFINE NOTE_SI2   4050
#DEFINE NOTE_DO3   3822
#DEFINE NOTE_DODIESE3   3608
#DEFINE NOTE_RE3   3405
#DEFINE NOTE_REDIESE3   3214
#DEFINE NOTE_MI3   3034
#DEFINE NOTE_FA3   2863
#DEFINE NOTE_FADIESE3   2703
#DEFINE NOTE_SOL3   2551
#DEFINE NOTE_SOLDIESE3   2408
#DEFINE NOTE_LA3   2273
#DEFINE NOTE_LADIESE3   2145
#DEFINE NOTE_SI3   2025
#DEFINE NOTE_DO4   1911
#DEFINE NOTE_DODIESE4   1804
#DEFINE NOTE_RE4   1703
#DEFINE NOTE_REDIESE4   1607
#DEFINE NOTE_MI4   1517
#DEFINE NOTE_FA4   1432
#DEFINE NOTE_FADIESE4   1351
#DEFINE NOTE_SOL4   1276
#DEFINE NOTE_SOLDIESE4   1204
#DEFINE NOTE_LA4   1136
#DEFINE NOTE_LADIESE4   1073
#DEFINE NOTE_SI4   1012
#DEFINE NOTE_DO5   956
#DEFINE NOTE_DODIESE5   902
#DEFINE NOTE_RE5   851
#DEFINE NOTE_REDIESE5   804
#DEFINE NOTE_MI5   758
#DEFINE NOTE_FA5   716
#DEFINE NOTE_FADIESE5   676
#DEFINE NOTE_SOL5   638
#DEFINE NOTE_SOLDIESE5   602
#DEFINE NOTE_LA5   568
#DEFINE NOTE_LADIESE5   536
#DEFINE NOTE_SI5   506
#DEFINE NOTE_DO6   478
#DEFINE NOTE_DODIESE6   451
#DEFINE NOTE_RE6   426
#DEFINE NOTE_REDIESE6   402
#DEFINE NOTE_MI6   379
#DEFINE NOTE_FA6   358
#DEFINE NOTE_FADIESE6   338
#DEFINE NOTE_SOL6   319
#DEFINE NOTE_SOLDIESE6   301
#DEFINE NOTE_LA6   284
#DEFINE NOTE_LADIESE6   268
#DEFINE NOTE_SI6   253
#DEFINE NOTE_DO7   239
#DEFINE NOTE_DODIESE7   225
#DEFINE NOTE_RE7   213
#DEFINE NOTE_REDIESE7   201
#DEFINE NOTE_MI7   190
#DEFINE NOTE_FA7   179
#DEFINE NOTE_FADIESE7   169
#DEFINE NOTE_SOL7   159
#DEFINE NOTE_SOLDIESE7   150
#DEFINE NOTE_LA7   142
#DEFINE NOTE_LADIESE7   134
#DEFINE NOTE_SI7   127



#int_TIMER0
void  TIMER0_isr(void) 
{

}


void playSound(unsigned int32 period,unsigned int32 duration){
   unsigned int32 timecounter=0;
   while(timecounter<duration){
      delay_us(period>>2);
      output_bit( PIN_BUZZER,0 );   
      delay_us(period>>2);
      output_bit( PIN_BUZZER,1 ); 
      
      timecounter+=period;
   }
}

void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   set_tris_a(0b00000011);
   set_tris_b(0b00000000);
   set_tris_c(0b10110011);
   set_tris_d(0b11110000);
   set_tris_e(0b00000100);
   
   while(1)
   {
  
      // waits for B1 to go high
      while ( !input(PIN_B1) )
      {}




   
      //PE-
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //tit
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //pa-
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //pa
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //Noe-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //el
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //Quand
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tu
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //Des-
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //cen-
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //dras
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //du
      playSound(NOTE_FA4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //ciel
      playSound(NOTE_MI4,TEMPS_BLANCHE);
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //A-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //vec
      playSound(NOTE_DO4,TEMPS_NOIRE);
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tes
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //jou-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //ets
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //par
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //mi-
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //liers
      playSound(NOTE_SOL3,TEMPS_BLANCHE);
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //N'ou-
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //blie
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //pas
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      delay_us(WAIT);
      //mon
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //pet-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tit
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //pa-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //nier
      playSound(NOTE_RE4,TEMPS_BLANCHE);
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //Mais
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //a-
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //vant
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //de
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //par-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //tir
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //il
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //fau-
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //dra
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //bien
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //te
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //cou-
      playSound(NOTE_FA4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //vrir
      playSound(NOTE_MI4,TEMPS_BLANCHE);
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //De-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //hors
      playSound(NOTE_DO4,TEMPS_NOIRE);
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //il
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //fait
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //dé-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //jà
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //bien
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //froid
      playSound(NOTE_SOL3,TEMPS_BLANCHE);
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //C'est
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //un
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //peu
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      delay_us(WAIT);
      //a
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //cau-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //se
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //de
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //Moi
      playSound(NOTE_DO4,TEMPS_RONDE);
      delay_us(WAIT);
      //--------------------------------
      //Il
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //me
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //tar-
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //de
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //tant
      playSound(NOTE_LA3,TEMPS_NOIRE);
      delay_us(WAIT);
      //que
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //le
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //jour
      playSound(NOTE_DO4,TEMPS_NOIRE);
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //se
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //lè-
      playSound(NOTE_LA3,TEMPS_NOIRE);
      delay_us(WAIT);
      //ve
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //Pour
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //voir
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //si
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tu
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //m'as
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //ap-
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //por-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //té
      playSound(NOTE_RE4,TEMPS_RONDE);
      delay_us(WAIT);
      //--------------------------------
      //tous
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //les
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //beaux
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //jou-
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //joux
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //que
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //je
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //vois
      playSound(NOTE_FA4,TEMPS_NOIRE);
      playSound(NOTE_FA4,TEMPS_CROCHE);
      delay_us(WAIT);
      //en
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //re-
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //ve
      playSound(NOTE_SI3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //et
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //que
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //je
      playSound(NOTE_MI4,TEMPS_CROCHE);
      delay_us(WAIT);
      //t'ai
      playSound(NOTE_FA4,TEMPS_NOIRE);
      delay_us(WAIT);
      //com-
      playSound(NOTE_FA4,TEMPS_CROCHE);
      delay_us(WAIT);
      //man-
      playSound(NOTE_FA4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //de
      playSound(NOTE_SOL4,TEMPS_BLANCHE);
      playSound(NOTE_SOL4,TEMPS_BLANCHE);
      delay_us(WAIT);
       //PE-
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //tit
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //pa-
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //pa
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //Noe-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //el
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //Quand
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tu
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //Des-
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //cen-
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //dras
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //du
      playSound(NOTE_FA4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //ciel
      playSound(NOTE_MI4,TEMPS_BLANCHE);
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //A-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //vec
      playSound(NOTE_DO4,TEMPS_NOIRE);
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tes
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //jou-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //ets
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //par
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //mi-
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //liers
      playSound(NOTE_SOL3,TEMPS_BLANCHE);
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //N'ou-
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //blie
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //pas
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      delay_us(WAIT);
      //mon
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //pet-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //tit
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //pa-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //nier
      playSound(NOTE_RE4,TEMPS_BLANCHE);
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //Mais
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //a-
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //vant
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //de
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //par-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //tir
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      //il
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //fau-
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //dra
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //bien
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //te
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //cou-
      playSound(NOTE_FA4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //vrir
      playSound(NOTE_MI4,TEMPS_BLANCHE);
      playSound(NOTE_MI4,TEMPS_NOIRE);
      delay_us(WAIT);
      //De-
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      //hors
      playSound(NOTE_DO4,TEMPS_NOIRE);
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //il
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //fait
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //dé-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //jà
      playSound(NOTE_SI3,TEMPS_CROCHE);
      delay_us(WAIT);
      //bien
      playSound(NOTE_LA3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //froid
      playSound(NOTE_SOL3,TEMPS_BLANCHE);
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //C'est
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //un
      playSound(NOTE_SOL3,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //peu
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      delay_us(WAIT);
      //a
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //cau-
      playSound(NOTE_DO4,TEMPS_CROCHE);
      delay_us(WAIT);
      //se
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //de
      playSound(NOTE_RE4,TEMPS_CROCHE);
      delay_us(WAIT);
      //--------------------------------
      //Moi
      playSound(NOTE_DO4,TEMPS_BLANCHE);
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      
      playSound(NOTE_SOL3,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      playSound(NOTE_LA3,TEMPS_NOIRE);
      delay_us(WAIT);
      playSound(NOTE_DO4,TEMPS_NOIRE);
      delay_us(WAIT);
      playSound(NOTE_RE4,TEMPS_NOIRE);
      delay_us(WAIT);
      playSound(NOTE_FA4,TEMPS_NOIRE);
      delay_us(WAIT);
      //--------------------------------
      playSound(NOTE_SOL4,TEMPS_RONDE);
      delay_us(WAIT);
   }
   
   
   
}


