#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    if( celcius <= 200.0f)
    {
        return 200; // Return 200 for ok
    }
    else 
    {
        return 500;//Return 500 for not-ok
    }
}
float farenheitToCelcius(float farenheit)
{
float celcius;
return(float (celcius = (farenheit - 32) * 5 / 9));
}


void alertInCelcius(float farenheit,int (*fpnetworkAlertStub)(float)) {
    float celcius = farenheitToCelcius(farenheit);
    int returnCode = fpnetworkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5,&networkAlertStub);
    assert(alertFailureCount == 1);
    alertInCelcius(500.6,&networkAlertStub);
    assert(alertFailureCount == 2);
    alertInCelcius(200.5,&networkAlertStub);
    assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
