if (!isServer) exitWith {};

while {true} do
{
    if (daytime >= 19 || daytime < 5) then   // after 7pm and before 5am time multiplier changes (10 in game hours)
    {
        setTimeMultiplier 20      // adjust this value for slower or faster night cycle ( 20 hours will take 1 hour )
    }
    else
    {
        setTimeMultiplier 6      // adjust this value for slower or faster day cycle  ( 6 hours will take 1 hour )
    };

    uiSleep 30;
};