#include "CubeTest.h"


#define PI 3.14159265


CubeTest::CubeTest() : CubeApplication(30){
    joysticks.push_back(new Joystick(0));
    joysticks.push_back(new Joystick(1));
    joysticks.push_back(new Joystick(2));
    joysticks.push_back(new Joystick(3));

    allTheColors.push_back(Color2::red());
    allTheColors.push_back(Color2::yellow());
    allTheColors.push_back(Color2::green());
    allTheColors.push_back(Color2::cyan());
    allTheColors.push_back(Color2::blue());
    allTheColors.push_back(Color2::pink());
    allTheColors.push_back(Color2::white());
    allTheColors.push_back(Color2::black());

    screenNames.push_back("front");
    screenNames.push_back("right");
    screenNames.push_back("back");
    screenNames.push_back("left");
    screenNames.push_back("top");
    screenNames.push_back("bottom");

}


bool CubeTest::loop() {
//    Declaration Part #################################################################################################
    static int maxTestMode = 9;

    static uint loopcount = 0;
    static int testMode = 9;
    static int oldTestMode = 4;
    static bool showMode = 1;
    static bool activeClear = 1;
    static int idxColor = 1;
    static int startX = 1;
    static int startY = 1;
    static float endX = 1;
    static float endY = 1;
    std::string testModeName = "Hello World!";
    time_t now = time(0);
    static int speed = 360;
    static int factorSpeed = 1;
    static int countAngle = 1;
    static int lengthHour = 16;
    static int lengthMin = 25;
    static int lengthSec = 30;
    static float angelHour = 0;
    static float angelMin = 0;
    static float angelSec = 0;
    static int hightLine = 6;
    static int offsetLine = 1;
    static int idxLine = 0;
    static bool done = 0;
    static Color2 colorLines = Color2(10,171,10);


//  Set Testmode #######################################################################################################
{ // only for collaps/expand -> no better solution so far
    // Arrorkeys Up/Down -> testMode
    testMode+=(int)joysticks.at(0)->getAxisPress(1);
    // if testMode has changed go in showMode 0 -> Show the Title of the next app on sceen and the number on cout
    if (oldTestMode != testMode) {
        //showMode = 0;
        std::cout << "testMode: " << testMode << std::endl;
    }
    // save the old Test mode 4 comarison
    oldTestMode = testMode;
    // check if the maxTestMode is too low - for now i have no better solution
    if(maxTestMode<testMode-1){
        maxTestMode = testMode-1;
        std::cout << "maxTestMode zu klein!!! Auf " << maxTestMode << " erhöhen!!!" << std::endl;
    }
}
//  Set showMode #######################################################################################################
{ // only for collaps/expand -> no better solution so far
        if (joysticks.at(0)->getButtonPress(0)) {
            // Button A -> showMode
            // Show Title of the Mode on Top screen
            showMode = !showMode;
            std::cout << "showMode: " << showMode << std::endl;
        }
    }
//  Set clear ##########################################################################################################
{ // only for collaps/expand -> no better solution so far
        if (joysticks.at(0)->getButtonPress(1)) {
            // Button A -> showMode
            // Show Title of the Mode on Top screen
            activeClear = !activeClear;
            std::cout << "activeClear: " << activeClear << std::endl;
        }
    }
//  clear screen #######################################################################################################
{ // only for collaps/expand -> no better solution so far
    if (activeClear) {
        //clear();
        fade(0.85);
    }
}
//  Show Button No #####################################################################################################
if (false) { // only for collaps/expand -> no better solution so far
    if (joysticks.at(0)->getButtonPress(0)) {
        std::cout << "Button 0" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(1)) {
        std::cout << "Button 1" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(2)) {
        std::cout << "Button 2" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(3)) {
        std::cout << "Button 3" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(4)) {
        std::cout << "Button 4" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(5)) {
        std::cout << "Button 5" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(6)) {
        std::cout << "Button 6" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(7)) {
        std::cout << "Button 7" << std::endl;
    }
    if (joysticks.at(0)->getButtonPress(8)) {
        std::cout << "Button 8" << std::endl;
    }
}
//  Select Testmode ####################################################################################################
    switch (testMode) {
        case 0:{
            testMode = maxTestMode;
            break;} // back to loop max
        case 1:{
            // Show Screens ############################################################################################
            // Generate 2 Lines at Sceen 0
            testModeName = "screen No 2D";
            if (showMode == 1) {

                //drawLine3D(Vector3i(0,0,CUBESIZE-loopcount%CUBESIZE),Vector3i(CUBESIZE,0,CUBESIZE-loopcount%CUBESIZE), Color2::red());
                //drawLine3D(Vector3i(loopcount%CUBESIZE,0,CUBESIZE),Vector3i(loopcount%CUBESIZE,0,0), Color2::blue());
                for( int a = 0; a < 6; a++ ) {
                    // ShowScreen Name and No in center of the screen
                    drawText((ScreenNumber)a, Vector2i(CharacterBitmaps::centered, CharacterBitmaps::centered), Color2::white(), "Screen " + std::to_string(a) + " " + screenNames[a]);

                    // Show Vectors in the corners
                    drawText((ScreenNumber)a, Vector2i(1, 1), Color2::white(), "x0y0");
                    drawText((ScreenNumber)a, Vector2i(1, CUBESIZE-6), Color2::white(), "x0y63");
                    drawText((ScreenNumber)a, Vector2i(CUBESIZE-20, 1), Color2::white(), "x63y0");
                    drawText((ScreenNumber)a, Vector2i(CUBESIZE-24, CUBESIZE-6), Color2::white(), "x63y63");

                    // Light up pixels in the corners
                    drawRect2D((ScreenNumber)a,0,0,0,0,allTheColors[0],false,allTheColors[idxColor]);
                    drawRect2D((ScreenNumber)a,0,CUBESIZE-1,0,CUBESIZE-1,allTheColors[1],false,allTheColors[idxColor]);
                    drawRect2D((ScreenNumber)a,CUBESIZE-1,0,CUBESIZE-1,0,allTheColors[2],false,allTheColors[idxColor]);
                    drawRect2D((ScreenNumber)a,CUBESIZE-1,CUBESIZE-1,CUBESIZE-1,CUBESIZE-1,allTheColors[4],false,allTheColors[idxColor]);

                }
            }
            break;
        }// Show Screens 2D
        case 2:{
            // Show Screens ############################################################################################
            // Generate 2 Lines at Sceen 0
            testModeName = "screen No 3D";
            if (showMode == 1) {

                //drawLine3D(Vector3i(0,0,CUBESIZE-loopcount%CUBESIZE),Vector3i(CUBESIZE,0,CUBESIZE-loopcount%CUBESIZE), Color2::red());
                //drawLine3D(Vector3i(loopcount%CUBESIZE,0,CUBESIZE),Vector3i(loopcount%CUBESIZE,0,0), Color2::blue());
                for( int a = 0; a < 6; a++ ) {
                    // ShowScreen Name and No in center of the screen
                    drawText((ScreenNumber) a, Vector2i(CharacterBitmaps::centered, CharacterBitmaps::centered),
                             Color2::white(), "Screen " + std::to_string(a) + " " + screenNames[a]);
                }
                // Coordinate system arrors
                // X in color red
                drawLine3D(Vector3i(26,4,0),Vector3i(34,4,0),Color2::red());
                drawLine3D(Vector3i(34,4,0),Vector3i(31,7,0),Color2::red());
                drawLine3D(Vector3i(34,4,0),Vector3i(31,1,0),Color2::red());
                drawText(ScreenNumber::top, Vector2i(35, CUBESIZE-6), Color2::red(), "x");
                // Y in color green
                drawLine3D(Vector3i(0,26,4),Vector3i(0,34,4),Color2::green());
                drawLine3D(Vector3i(0,34,4),Vector3i(0,31,7),Color2::green());
                drawLine3D(Vector3i(0,34,4),Vector3i(0,31,1),Color2::green());
                drawText(ScreenNumber::left, Vector2i(25, 1), Color2::green(), "Y");
                // Z in color blue
                drawLine3D(Vector3i(4,0,8),Vector3i(4,0,16),Color2::blue());
                drawLine3D(Vector3i(4,0,16),Vector3i(7,0,13),Color2::blue());
                drawLine3D(Vector3i(4,0,16),Vector3i(1,0,13),Color2::blue());
                drawText(ScreenNumber::front, Vector2i(2, 17), Color2::blue(), "Z");
                // Light up pixels in the corners
                // Corner 1 (0,0,0)
                setPixel3D(1,1,0,allTheColors[1]);
                drawText(ScreenNumber::top, Vector2i(1, CUBESIZE-6), Color2::white(), "x1y1z0");
                setPixel3D(0,1,1,allTheColors[3]);
                drawText(ScreenNumber::left, Vector2i(CUBESIZE-24, 1), Color2::white(), "x0y1z1");
                setPixel3D(1,0,1,allTheColors[5]);
                drawText(ScreenNumber::front, Vector2i(1, 1), Color2::white(), "x1y0z1");




            }
            break;}// Show Screens 3D
        case 3:{
            // Test Color ##############################################################################################
            // SchoulderButtons to change Color
            testModeName = "Test Color";

            //  Set Test Color #########################################################################################
            if (true) { // only for collaps/expand -> no better solution so far
                if (joysticks.at(0)->getButtonPress(6)) {
                    idxColor--;
                    if (idxColor < 0) {
                        idxColor = allTheColors.size() - 1;
                    }
                    std::cout << "testColor: " << idxColor << std::endl;
                }
                if (joysticks.at(0)->getButtonPress(7)) {
                    idxColor++;
                    if (idxColor >= allTheColors.size()) {
                        idxColor = 0;
                    }
                    std::cout << "testColor: " << idxColor << std::endl;
                }
            }

            if (showMode == 1) {
                fillAll(allTheColors[idxColor]);
            }
            break;}// Test Color
        case 4:{
            // Draw Lines ##############################################################################################
            testModeName = "Draw Lines";
            if (showMode == 1) {

                switch ((loopcount%256)/64) {
                    case 0:
                        startX = CUBESIZE/2-1;
                        startY = CUBESIZE/2-1;
                        endX = loopcount%CUBESIZE;
                        endY = 0;
                        break;
                    case 1:
                        startX = CUBESIZE/2;
                        startY = CUBESIZE/2-1;
                        endX = 64;
                        endY = loopcount%CUBESIZE;
                        break;
                    case 2:
                        startX = CUBESIZE/2;
                        startY = CUBESIZE/2;
                        endX = 64-loopcount%CUBESIZE;
                        endY = 64;
                        break;
                    case 3:
                        startX = CUBESIZE/2-1;
                        startY = CUBESIZE/2;
                        endX = 0;
                        endY = 64-loopcount%CUBESIZE;
                        break;
                }
                for( int a = 0; a < 6; a++ ) {

                    //drawLine2D((ScreenNumber)a, startX, startY, endX, endY, allTheColors[(loopcount%(4*CUBESIZE*(allTheColors.size()-1)))/(4*CUBESIZE)]);
                    drawLine2D((ScreenNumber)a, startX, startY, endX, endY, allTheColors[(loopcount%(4*CUBESIZE*(allTheColors.size()-1)))/(4*CUBESIZE)]);

                    for (int i=33;i<50;i++) {
                        drawCircle2D((ScreenNumber) a, startX, startY, i, Color2::black());
                        drawCircle2D((ScreenNumber) a, startX - 1, startY, i, Color2::black());
                        drawCircle2D((ScreenNumber) a, startX, startY - 1, i, Color2::black());
                        drawCircle2D((ScreenNumber) a, startX - 1, startY - 1, i, Color2::black());
                    }
                }
            }
            break;}// Draw Lines
        case 5:{
            // Draw Rectangle ##########################################################################################
            testModeName = "Draw Rectangle";
                if (showMode == 1) {
                    drawRect2D(top, 10, 20, 50, 60, Color2::red(), true, Color2::green());
                }
            break;}// Draw Rectangle
        case 6:{
            // Clock ###################################################################################################
            testModeName = "Clock";
            if (showMode == 1) {
                tm *ltm = localtime(&now);
                startX = CUBESIZE/2;
                startY = CUBESIZE/2;
//                angelHour = (ltm->tm_hour*60+ltm->tm_min)%360*PI/180;
                angelHour = (((ltm->tm_hour+1)%12*30)+(ltm->tm_min/2)-90)*PI/180;
                angelMin  = (ltm->tm_min %60*6-90) *PI/180;
                angelSec  = (ltm->tm_sec %60*6-90) *PI/180;
                for( int a = 0; a < 4; a++ ) {
                    drawText((ScreenNumber)a, Vector2i(28, 1),Color2::white(), "12");
                    drawText((ScreenNumber)a, Vector2i(45, 5),Color2::pink(), "1");
                    drawText((ScreenNumber)a, Vector2i(55, 15),Color2::white(), "2");
                    drawText((ScreenNumber)a, Vector2i(60, 30),Color2::white(), "3");
                    drawText((ScreenNumber)a, Vector2i(55, 45),Color2::white(), "4");
                    drawText((ScreenNumber)a, Vector2i(45, 54),Color2::white(), "5");
                    drawText((ScreenNumber)a, Vector2i(30, 58),Color2::white(), "6");
                    drawText((ScreenNumber)a, Vector2i(15, 54),Color2::white(), "7");
                    drawText((ScreenNumber)a, Vector2i(6, 45),Color2::white(), "8");
                    drawText((ScreenNumber)a, Vector2i(1, 30),Color2::white(), "9");
                    drawText((ScreenNumber)a, Vector2i(5, 15),Color2::white(), "10");
                    drawText((ScreenNumber)a, Vector2i(15, 5),Color2::white(), "11");

                    for (int i=33;i<50;i++) {
                        drawCircle2D((ScreenNumber) a, startX, startY, i, Color2(50, 50, 50));
                        drawCircle2D((ScreenNumber) a, startX - 1, startY, i, Color2(50, 50, 50));
                        drawCircle2D((ScreenNumber) a, startX, startY - 1, i, Color2(50, 50, 50));
                        drawCircle2D((ScreenNumber) a, startX - 1, startY - 1, i, Color2(50, 50, 50));
                    }

                    drawLine2D((ScreenNumber)a, startX, startY, cos(angelSec)*lengthSec+startX, sin(angelSec)*lengthSec+startY, allTheColors[1]);
                    drawLine2D((ScreenNumber)a, startX-1, startY, cos(angelSec)*lengthSec+startX, sin(angelSec)*lengthSec+startY, allTheColors[1]);
                    drawLine2D((ScreenNumber)a, startX, startY-1, cos(angelSec)*lengthSec+startX, sin(angelSec)*lengthSec+startY, allTheColors[1]);
                    drawLine2D((ScreenNumber)a, startX-1, startY-1, cos(angelSec)*lengthSec+startX, sin(angelSec)*lengthSec+startY, allTheColors[1]);
                    drawLine2D((ScreenNumber)a, startX, startY, cos(angelMin)*lengthMin+startX, sin(angelMin)*lengthMin+startY, allTheColors[2]);
                    drawLine2D((ScreenNumber)a, startX-1, startY, cos(angelMin)*lengthMin+startX, sin(angelMin)*lengthMin+startY, allTheColors[2]);
                    drawLine2D((ScreenNumber)a, startX, startY-1, cos(angelMin)*lengthMin+startX, sin(angelMin)*lengthMin+startY, allTheColors[2]);
                    drawLine2D((ScreenNumber)a, startX-1, startY-1, cos(angelMin)*lengthMin+startX, sin(angelMin)*lengthMin+startY, allTheColors[2]);
                    drawLine2D((ScreenNumber)a, startX, startY, cos(angelHour)*lengthHour+startX, sin(angelHour)*lengthHour+startY, allTheColors[3]);
                    drawLine2D((ScreenNumber)a, startX-1, startY, cos(angelHour)*lengthHour+startX, sin(angelHour)*lengthHour+startY, allTheColors[3]);
                    drawLine2D((ScreenNumber)a, startX, startY-1, cos(angelHour)*lengthHour+startX, sin(angelHour)*lengthHour+startY, allTheColors[3]);
                    drawLine2D((ScreenNumber)a, startX-1, startY-1, cos(angelHour)*lengthHour+startX, sin(angelHour)*lengthHour+startY, allTheColors[3]);
                }
            }
            break;}// Clock
        case 7:{
            // Show Font ###############################################################################################
            testModeName = "Font";
            if (showMode == 1) {
                idxLine = 0;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "Font 5x3px");
                idxLine++;
                idxLine++;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "A B C D E F G");
                idxLine++;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "H I J K L M N");
                idxLine++;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "O P Q R S T U");
                idxLine++;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "V W X Y Z");
                idxLine++;
                idxLine++;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "0 1 2 3 4 5");
                idxLine++;
                drawText(ScreenNumber::front, Vector2i(1, offsetLine+idxLine*hightLine),Color2::white(), "6 7 8 9");
                idxLine++;
            }
            break;}// Show Font
        case 8:{
            // Pixel move ##############################################################################################
            testModeName = "Pixel move";
            if (showMode == 1) {
                angelSec  = (loopcount%360) *PI/180;
                startX = cos(angelSec)*30+CUBESIZE/2;
                startY = sin(angelSec)*30+CUBESIZE/2;
                drawLine2D(ScreenNumber::top, startX, startY, startX, startY, Color2::pink());

            }
            break;}// Pixel move
        case 9:{
            // Draw Lines ##############################################################################################
            testModeName = "Draw Lines";
            if (showMode == 1) {
                switch ((loopcount%256)/64) {
                    case 0:
                        endX = loopcount%CUBESIZE;
                        endY = 0;
                        break;
                    case 1:
                        endX = 64;
                        endY = loopcount%CUBESIZE;
                        break;
                    case 2:
                        endX = 64-loopcount%CUBESIZE;
                        endY = 64;
                        break;
                    case 3:
                        endX = 0;
                        endY = 64-loopcount%CUBESIZE;
                        break;
                }
                startX = CUBESIZE/2;
                startY = CUBESIZE/2;
                if(loopcount%15==0){
                    //getRandomPointOnScreen(ScreenNumber::anyScreen)
                }
                for( int a = 0; a < 6; a++ ) {
                    drawLine2D((ScreenNumber)a, startX, startY, endX, endY, colorLines);
                    for (int i=32;i<50;i++) {
                        drawCircle2D((ScreenNumber) a, startX, startY, i, Color2::black());
                        drawCircle2D((ScreenNumber) a, startX-1, startY, i, Color2::black());
                        drawCircle2D((ScreenNumber) a, startX, startY-1, i, Color2::black());
                        drawCircle2D((ScreenNumber) a, startX-1, startY-1, i, Color2::black());
                    }
                    drawCircle2D((ScreenNumber)a, startX, startY,10,colorLines);
                    drawCircle2D((ScreenNumber)a, startX, startY,20,colorLines);
                    drawCircle2D((ScreenNumber)a, startX, startY,30,colorLines);
                }
            }
            break;}// Draw Lines2
        default:
            testMode = 1;
            break;
    }
//   show Titles #######################################################################################################
    if (showMode == 0) {
        for( int a = 0; a < 6; a++ ) {
            drawText((ScreenNumber)a, Vector2i(CharacterBitmaps::centered, CharacterBitmaps::centered),Color2::white(), testModeName);
        }
    }
//   do other important stuff ##########################################################################################
    joysticks.at(0)->clearAllButtonPresses();
    render();
    loopcount++;
    return true;
}