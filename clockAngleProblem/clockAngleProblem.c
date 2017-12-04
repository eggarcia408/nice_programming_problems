#include <stdio.h>
#include <math.h>

/*

Description:

    This application will execute the SMALLEST angle between the 
    small and big hand of the clock. You must account for the small
    hand slightly moving when the big hand is moving    

    Examples:
        Time: 4:35
            smallest angle between hands is ~72.5

        Time: 3:02
            smallest angle between hands is ~79


        Time: 1:40
            smallest angle between hands is ~170

*/

double angleBetweenHands(unsigned int hour_p, unsigned int minutes_p);

int main(int argc, char **argv)
{
    unsigned int hour;
    unsigned int minutes;   
    char timeOfDay[3];      //will indicate am or pm

    printf("Please input hour: ");
    scanf("%u",&hour);
    printf("Please input minutes: ");
    scanf("%u",&minutes);
    
    printf("Please enter am or pm for the time of day: ");
    scanf("%2s",timeOfDay);

    printf("It is %u:%u%s\n\n",hour,minutes,timeOfDay);

    printf("Smallest angle between hands is: %.2f", angleBetweenHands(hour, minutes));    

        
    return 0;
}

double angleBetweenHands(unsigned int hour_p, unsigned int  minutes_p)
{

    double angleBigHand;        //hold angle of big hand(minutes)

    double rawAngleSmallHand;   //will hold angle of small hand(hours) without
                                //accounting for small delta angle move

    double smallHandDeltaAngle; //will hold small angle(hours) delta 

    angleBigHand        = minutes_p * 6; //calculate angle of big hand(minutes)

    rawAngleSmallHand   = hour_p * 30;  //calculate raw angle of small hand
    
    smallHandDeltaAngle = ((double)minutes_p/60) * 30; //calculates delta angle of 
                                               //small hand by getting percent
                                               //of minutes and multiplying
                                               //it by thirty degrees
/*For debugging purposes
    
    printf("anglebighand %.2f\n",angleBigHand);
    printf("rawAnglesmallHand %.2f\n",rawAngleSmallHand);
    printf("smallHandDeltaAngle %.2f\n",smallHandDeltaAngle);
*/
    if( fabs(angleBigHand-(rawAngleSmallHand + smallHandDeltaAngle) ) > 180 )
        return 360 - fabs(angleBigHand-(rawAngleSmallHand + smallHandDeltaAngle ) );

    else
        return fabs(angleBigHand-(rawAngleSmallHand + smallHandDeltaAngle ) );
      

}
