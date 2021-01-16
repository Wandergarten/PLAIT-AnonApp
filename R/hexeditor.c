//
//  hexeditor.c
//  HelloWorld
//
//  Created by Jonas Schulz-Marner on 12.08.20.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void hexeditor(char* filepath[]){
    FILE *fp;
    char temp, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12, temp13, end_of_name, end_of_filename, end_of_originalguid, end_of_guid, end_of_fil;
    int i;
    int count_name, count_filename, count_originalguid, count_guid, count_fil;  //diese Variable zählt die Länge des Namens bzw. Dateinamens
   
    
    bool setname = false, set_filename = false, set_originalguid = false, set_guid = false, set_fil = false;
    char anon_name[100] = "";
    char anon_filename[100] = "";
    char anon_originalguid[100] = "";
    char anon_guid[100] = "";
    char anon_fil[100] = "";
    char x[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";


    fp = fopen(*filepath, "rb+");
    
    
    if(fp != NULL) {

        for (i=0; i<300000000; i++) {        //Vorschleife durch die ganze Datei laufen lassen. i ist immer dort, wo unser filepointer fp ist
            
            //Verschachtelte if-Abfragen, ob die Buchstaben in der richtigen Reihenfolge in der Datei enthalten sind
            
            //SAMPLEID1, FILENAME, ORIGINALGUID, GUID, $FIL
            //von Elmar vorgeschlagen: $SRC (ist vorhanden aber leer), SAMPLE NAME (nicht auffindbar), EXPERIMENT NAME
            
            //SAMPLEID1
            
            fscanf(fp, "%c", &temp);
            if (temp == '\\'){      // '\\' bedeutet hier '\'
                i = i+1;
            fscanf(fp, "%c", &temp1);
            if (temp1 == '@'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'S'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'M'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'P'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp10);
            if (temp10 == '1'){
                i = i+1;
            fscanf(fp, "%c", &temp11);
            if (temp11 == '\\'){
                i = i+1;
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_name);
                count_name = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_name != '\\'){
                    fscanf(fp, "%c", &end_of_name);
                    count_name = count_name + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (setname == false){
                    strncat(anon_name, x, count_name - 1);
                    setname = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_name,fp);
                i = i + count_name - 1;
            }}}}}}}}}}}
                
                //FILENAME
                
            else if (temp1 == 'F'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'N'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'M'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == '\\'){
                i = i+1;
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_filename);
                count_filename = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_filename != '\\'){
                    fscanf(fp, "%c", &end_of_filename);
                    count_filename = count_filename + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_filename == false){
                    strncat(anon_filename, x, count_filename - 1);
                    set_filename = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_filename,fp);
                i = i + count_filename - 1;
            }}}}}}}}}
                
                //ORIGINALGUID
                
            else if (temp1 == 'O'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'R'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'N'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp10);
            if (temp10 == 'U'){
                i = i+1;
            fscanf(fp, "%c", &temp11);
            if (temp11 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp12);
            if (temp12 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp13);
            if (temp13 == '\\'){
                i = i+1;
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_originalguid);
                count_originalguid = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_originalguid != '\\'){
                    fscanf(fp, "%c", &end_of_originalguid);
                    count_originalguid = count_originalguid + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_originalguid == false){
                    strncat(anon_originalguid, x, count_originalguid - 1);
                    set_originalguid = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_originalguid,fp);
                i = i + count_originalguid - 1;
            }}}}}}}}}}}}}
                
                
                //GUID
                
            else if (temp1 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'U'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == '\\'){
                i = i+1;
            
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_guid);
                count_guid = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_guid != '\\'){
                    fscanf(fp, "%c", &end_of_guid);
                    count_guid = count_guid + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_guid == false){
                    strncat(anon_guid, x, count_guid - 1);
                    set_guid = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_guid,fp);
                i = i + count_guid - 1;
            }}}}}
                
                
                //$FIL
                
            else if (temp1 == '$'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'F'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == '\\'){
                i = i+1;
            
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_fil);
                count_fil = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_fil != '\\'){
                    fscanf(fp, "%c", &end_of_fil);
                    count_fil = count_fil + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_fil == false){
                    strncat(anon_fil, x, count_fil - 1);
                    set_fil = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_fil,fp);
                i = i + count_fil - 1;
            }}}}}
            }
            
            
            
            
            
            
            // andere Trennzeichen für FCS 3.0
            
            else if (temp == '|'){
                i = i+1;
            fscanf(fp, "%c", &temp1);
            if (temp1 == '@'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'S'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'M'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'P'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp10);
            if (temp10 == '1'){
                i = i+1;
            fscanf(fp, "%c", &temp11);
            if (temp11 == '|'){
                i = i+1;
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_name);
                count_name = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_name != '|'){
                    fscanf(fp, "%c", &end_of_name);
                    count_name = count_name + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (setname == false){
                    strncat(anon_name, x, count_name - 1);
                    setname = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_name,fp);
                i = i + count_name - 1;
            }}}}}}}}}}}
                
                //FILENAME
                
            else if (temp1 == 'F'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'N'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'M'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == '|'){
                i = i+1;

                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_filename);
                count_filename = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_filename != '|'){
                    fscanf(fp, "%c", &end_of_filename);
                    count_filename = count_filename + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_filename == false){
                    strncat(anon_filename, x, count_filename - 1);
                    set_filename = true;
                }
                
                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_filename,fp);
                i = i + count_filename - 1;
            }}}}}}}}}
                
                
                //ORIGINALGUID
                
            else if (temp1 == 'O'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'R'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'N'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp10);
            if (temp10 == 'U'){
                i = i+1;
            fscanf(fp, "%c", &temp11);
            if (temp11 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp12);
            if (temp12 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp13);
            if (temp13 == '|'){
                i = i+1;
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_originalguid);
                count_originalguid = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_originalguid != '|'){
                    fscanf(fp, "%c", &end_of_originalguid);
                    count_originalguid = count_originalguid + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_originalguid == false){
                    strncat(anon_originalguid, x, count_originalguid - 1);
                    set_originalguid = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_originalguid,fp);
                i = i + count_originalguid - 1;
            }}}}}}}}}}}}}
                
                
                //GUID
                
            else if (temp1 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'U'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == '|'){
                i = i+1;
            
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_guid);
                count_guid = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_guid != '|'){
                    fscanf(fp, "%c", &end_of_guid);
                    count_guid = count_guid + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_guid == false){
                    strncat(anon_guid, x, count_guid - 1);
                    set_guid = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_guid,fp);
                i = i + count_guid - 1;
            }}}}}
                
                
                //$FIL
                
            else if (temp1 == '$'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'F'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == '|'){
                i = i+1;
                
            
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_fil);
                count_fil = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_fil != '|'){
                    fscanf(fp, "%c", &end_of_fil);
                    count_fil = count_fil + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_fil == false){
                    strncat(anon_fil, x, count_fil - 1);
                    set_fil = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_fil,fp);
                i = i + count_fil - 1;
            }}}}}
            }
            
 
        
            // andere Trennzeichen für .fcs
            
            else if (temp == '.'){
                i = i+1;
            fscanf(fp, "%c", &temp1);
            if (temp1 == '@'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'S'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'M'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'P'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp10);
            if (temp10 == '1'){
                i = i+1;
            fscanf(fp, "%c", &temp11);
            if (temp11 == '.'){
                i = i+1;
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_name);
                count_name = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_name != '.'){
                    fscanf(fp, "%c", &end_of_name);
                    count_name = count_name + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (setname == false){
                    strncat(anon_name, x, count_name - 1);
                    setname = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_name,fp);
                i = i + count_name - 1;
            }}}}}}}}}}}
                
                //FILENAME
                
            else if (temp1 == 'F'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'N'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'M'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'E'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == '.'){
                i = i+1;

                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_filename);
                count_filename = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_filename != '.'){
                    fscanf(fp, "%c", &end_of_filename);
                    count_filename = count_filename + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_filename == false){
                    strncat(anon_filename, x, count_filename - 1);
                    set_filename = true;
                }
                
                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_filename,fp);
                i = i + count_filename - 1;
            }}}}}}}}}
                
                
                //ORIGINALGUID
                
            else if (temp1 == 'O'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'R'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp6);
            if (temp6 == 'N'){
                i = i+1;
            fscanf(fp, "%c", &temp7);
            if (temp7 == 'A'){
                i = i+1;
            fscanf(fp, "%c", &temp8);
            if (temp8 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp9);
            if (temp9 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp10);
            if (temp10 == 'U'){
                i = i+1;
            fscanf(fp, "%c", &temp11);
            if (temp11 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp12);
            if (temp12 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp13);
            if (temp13 == '.'){
                i = i+1;
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_originalguid);
                count_originalguid = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_originalguid != '.'){
                    fscanf(fp, "%c", &end_of_originalguid);
                    count_originalguid = count_originalguid + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_originalguid == false){
                    strncat(anon_originalguid, x, count_originalguid - 1);
                    set_originalguid = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_originalguid,fp);
                i = i + count_originalguid - 1;
            }}}}}}}}}}}}}
                
                
                //GUID
                
            else if (temp1 == 'G'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'U'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'D'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == '.'){
                i = i+1;
            
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_guid);
                count_guid = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_guid != '.'){
                    fscanf(fp, "%c", &end_of_guid);
                    count_guid = count_guid + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_guid == false){
                    strncat(anon_guid, x, count_guid - 1);
                    set_guid = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_guid,fp);
                i = i + count_guid - 1;
            }}}}}
                
                
                //$FIL
                
            else if (temp1 == '$'){
                i = i+1;
            fscanf(fp, "%c", &temp2);
            if (temp2 == 'F'){
                i = i+1;
            fscanf(fp, "%c", &temp3);
            if (temp3 == 'I'){
                i = i+1;
            fscanf(fp, "%c", &temp4);
            if (temp4 == 'L'){
                i = i+1;
            fscanf(fp, "%c", &temp5);
            if (temp5 == '.'){
                i = i+1;
                
            
            
                //printf("Gefunden bei %d\n", i);
                fscanf(fp, "%c", &end_of_fil);
                count_fil = 0;
                
                // Zähle, wie lange der Name ist
                while (end_of_fil != '.'){
                    fscanf(fp, "%c", &end_of_fil);
                    count_fil = count_fil + 1;
                }
                
                // anonymisierten Namen setzen
                // -1 rechnen, weil in FCS-Datei wird automatisch vor den neuen String eine 0 gesetzt
                if (set_fil == false){
                    strncat(anon_fil, x, count_fil - 1);
                    set_fil = true;
                }

                // Datei an der passenden Stelle überschreiben
                fseek(fp, i, SEEK_SET);
                fputs(anon_fil,fp);
                i = i + count_fil - 1;
            }}}}}
            }
            
            
            
        }
        
            

        
    }
    
    fclose(fp);

}
