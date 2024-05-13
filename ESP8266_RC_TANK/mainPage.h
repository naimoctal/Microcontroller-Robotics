const char MAIN_page[] PROGMEM = R"=====(
<html>
    <title>ESP8266 Tank Controller</title>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
            html, body {
                width:100%;
                height:100%;
            }
            body {
                margin: 0;
                padding: 0;
                font-family: sans-serif;
                background-color: black;
                background-image: url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iaXNvLTg4NTktMSI/Pg0KPCEtLSBVcGxvYWRlZCB0bzogU1ZHIFJlcG8sIHd3dy5zdmdyZXBvLmNvbSwgR2VuZXJhdG9yOiBTVkcgUmVwbyBNaXhlciBUb29scyAtLT4NCjxzdmcgdmVyc2lvbj0iMS4xIiBpZD0iTGF5ZXJfMSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiB4bWxuczp4bGluaz0iaHR0cDovL3d3dy53My5vcmcvMTk5OS94bGluayIgDQoJIHZpZXdCb3g9IjAgMCA1MTIgNTEyIiB4bWw6c3BhY2U9InByZXNlcnZlIj4NCjxwb2x5Z29uIHN0eWxlPSJmaWxsOiMwMDk1NEE7IiBwb2ludHM9IjUwNC4wODIsMzAzLjUwNSA1MDQuMDgyLDQxNC4zNTEgMzI0LjA5MSwzMDQuMzUgMzI0LjYxOSwzMDMuNTA1IDM5OC41MTUsMjM0Ljg4NyAiLz4NCjxwb2x5Z29uIHN0eWxlPSJmaWxsOiMwRUIxNEM7IiBwb2ludHM9IjUwNC4wODIsNDE0LjM1MSA1MDQuMDgyLDQ1MS4yOTkgNy45MTgsNDUxLjI5OSA3LjkxOCwzNzcuNDAyIDIxOS4wNTIsMjQwLjE2NSANCgkzMjQuMDkxLDMwNC4zNSAiLz4NCjxwb2x5Z29uIHN0eWxlPSJmaWxsOiMwMDcxQkM7IiBwb2ludHM9IjUwNC4wODIsNjAuNzAxIDUwNC4wODIsMzAzLjUwNSAzOTguNTE1LDIzNC44ODcgMzI0LjYxOSwzMDMuNTA1IDMyNC4wOTEsMzA0LjM1IA0KCTIxOS4wNTIsMjQwLjE2NSA3LjkxOCwzNzcuNDAyIDcuOTE4LDYwLjcwMSAiLz4NCjxwb2x5Z29uIHN0eWxlPSJmaWxsOiMwMDg2NDc7IiBwb2ludHM9IjUwNC4wODIsMzcxLjUxNSAzNTUuNzk0LDI3NC41NTcgMzI0LjYxOSwzMDMuNTA1IDMyNC4wOTEsMzA0LjM1IDUwNC4wODIsNDE0LjM1MSAiLz4NCjxwb2x5Z29uIHN0eWxlPSJmaWxsOiMwMEFCNEY7IiBwb2ludHM9IjUwNC4wODIsNDUxLjI5OSA1MDQuMDgyLDQxNC4zNTEgMzI0LjA5MSwzMDQuMzUgMjE5LjA1MiwyNDAuMTY1IDE4MC40MjIsMjY1LjI3NCANCgk0OTYuMzE1LDQ1MS4yOTkgIi8+DQo8cG9seWdvbiBzdHlsZT0iZmlsbDojMDA4OUNDOyIgcG9pbnRzPSI3LjkxOCw2MC43MDEgNy45MTgsMzc3LjQwMiAyMTkuMDUyLDI0MC4xNjUgMjU2LDI2Mi43NDMgMjU2LDYwLjcwMSAiLz4NCjxwYXRoIHN0eWxlPSJmaWxsOiNGRkQzMTE7IiBkPSJNMzA2LjE0NCwxMDIuOTI4YzMwLjYxNCwwLDU1LjQyMywyNC44MDgsNTUuNDIzLDU1LjQyM3MtMjQuODA4LDU1LjQyMy01NS40MjMsNTUuNDIzDQoJcy01NS40MjMtMjQuODA4LTU1LjQyMy01NS40MjNTMjc1LjUzLDEwMi45MjgsMzA2LjE0NCwxMDIuOTI4eiIvPg0KPHBhdGggc3R5bGU9ImZpbGw6I0ZBQkIxQjsiIGQ9Ik0yNzcuMTY2LDExMS4yOTljLTE1LjgxNCw5Ljc2LTI2LjQ0NSwyNy4wOTktMjYuNDQ1LDQ3LjA1MWMwLDMwLjYxNCwyNC44MDgsNTUuNDIzLDU1LjQyMyw1NS40MjMNCgljMTQuNjczLDAsMjcuOTE5LTUuODA1LDM3LjgzMy0xNS4xMUMzMTEuNjA3LDE3OS41NTIsMjg3LjMxMiwxNDguNDEsMjc3LjE2NiwxMTEuMjk5eiIvPg0KPHBhdGggc3R5bGU9ImZpbGw6I0YxRjJGMjsiIGQ9Ik0xNTUuNzExLDEzOS44NzZjMTQuNTY4LDAsMjYuMzkyLDExLjgyNCwyNi4zOTIsMjYuMzkycy0xMS44MjQsMjYuMzkyLTI2LjM5MiwyNi4zOTINCglzLTU1Ljg0NSwwLTY4LjYxOSwwYy0xNC41NjgsMC0yNi4zOTItMTEuODI0LTI2LjM5Mi0yNi4zOTJzMTEuODI0LTI2LjM5MiwyNi4zOTItMjYuMzkyYzAuMjExLDAsMC4zMTcsMCwwLjUyOCwwLjEwNg0KCWMyLjQyOC0xMi4xNCwxMy4wOS0yMS4yMTksMjUuODY0LTIxLjIxOWMxNC41NjgsMCwyNi4zOTIsMTEuODIzLDI2LjM5MiwyNi4zOTJ2MC4xMDYNCglDMTQ0LjMxLDE0MS45ODgsMTQ5LjY5NCwxMzkuODc2LDE1NS43MTEsMTM5Ljg3NnoiLz4NCjxwYXRoIGQ9Ik0wLDUyLjc4NHY0MDYuNDMzaDUxMlY1Mi43ODRIMHogTTQ5Ni4xNjUsNjguNjE5djIyMC4yOTdsLTk4LjUxMi02NC4wMzNsLTc0Ljc4OCw2OS40NDVsLTEwMy45NDQtNjMuNTIyTDE1LjgzNSwzNjIuODEzDQoJVjY4LjYxOUg0OTYuMTY1eiBNNDk2LjE2NSw0MDAuMjMzTDMzNi45LDMwMi45MDVsNjIuNDc3LTU4LjAxNWw5Ni43ODgsNjIuOTEzVjQwMC4yMzN6IE0xNS44MzUsNDQzLjM4MXYtNjEuNjgzbDIwMy4zNDYtMTMyLjE3NQ0KCWwxMDAuNzgsNjEuNTgxbDE3Ni4yMDQsMTA3LjY4NnYyNC41OTFIMTUuODM1eiIvPg0KPHBhdGggZD0iTTMwNi4xNDQsMjIxLjY5MWMzNC45MjYsMCw2My4zNC0yOC40MTQsNjMuMzQtNjMuMzRzLTI4LjQxNC02My4zNC02My4zNC02My4zNHMtNjMuMzQsMjguNDE0LTYzLjM0LDYzLjM0DQoJUzI3MS4yMTksMjIxLjY5MSwzMDYuMTQ0LDIyMS42OTF6IE0zMDYuMTQ0LDExMC44NDVjMjYuMTk0LDAsNDcuNTA1LDIxLjMxMSw0Ny41MDUsNDcuNTA1cy0yMS4zMTEsNDcuNTA1LTQ3LjUwNSw0Ny41MDUNCglzLTQ3LjUwNS0yMS4zMTEtNDcuNTA1LTQ3LjUwNVMyNzkuOTUsMTEwLjg0NSwzMDYuMTQ0LDExMC44NDV6Ii8+DQo8cGF0aCBkPSJNODcuMDkzLDIwMC41NzdoNjguNjE5YzE4LjkxOCwwLDM0LjMwOS0xNS4zOTIsMzQuMzA5LTM0LjMwOXMtMTUuMzkyLTM0LjMwOS0zNC4zMDktMzQuMzA5DQoJYy0zLjM4OCwwLTYuNzMzLDAuNTE3LTkuOTYxLDEuNTI1Yy00Ljc4NS0xMy4xOTEtMTcuNDQzLTIyLjYzOS0zMi4yNjUtMjIuNjM5Yy0xNC4xNTQsMC0yNi42ODgsOC43Ni0zMS44MjcsMjEuNTQzDQoJYy0xNi4zNDQsMi42MTQtMjguODc0LDE2LjgxLTI4Ljg3NCwzMy44OEM1Mi43ODQsMTg1LjE4Niw2OC4xNzUsMjAwLjU3Nyw4Ny4wOTMsMjAwLjU3N3ogTTg1LjY1NCwxNDcuODUxbDcuNjk4LDMuODQ5bDIuMDMzLTEwLjE2NQ0KCWMxLjcyMS04LjYwNyw5LjMzMy0xNC44NTQsMTguMDk5LTE0Ljg1NGMxMC4xODYsMCwxOC40NzQsOC4yODgsMTguNDc0LDE4LjQ3NHYxNS43OTFsMTIuNjE5LTkuMzE0DQoJYzMuNDUtMi41NDYsNy4xOTUtMy44MzYsMTEuMTMzLTMuODM2YzEwLjE4NiwwLDE4LjQ3NCw4LjI4OCwxOC40NzQsMTguNDc0YzAsMTAuMTg2LTguMjg4LDE4LjQ3NC0xOC40NzQsMTguNDc0SDg3LjA5Mw0KCWMtMTAuMTg2LDAtMTguNDc0LTguMjg4LTE4LjQ3NC0xOC40NzRDNjguNjE5LDE1Ni41NzIsNzYuMTI2LDE0OC41OTYsODUuNjU0LDE0Ny44NTF6Ii8+DQo8Zz4NCgkNCgkJPHJlY3QgeD0iMjA0Ljg5MiIgeT0iMzI5LjkxIiB0cmFuc2Zvcm09Im1hdHJpeCgtMC44NTI2IC0wLjUyMjYgMC41MjI2IC0wLjg1MjYgMzgwLjgxMjMgNzgzLjA3ODYpIiBzdHlsZT0iZmlsbDojRkZGRkZGOyIgd2lkdGg9IjE5MS45MjQiIGhlaWdodD0iMTUuODM1Ii8+DQoJDQoJCTxyZWN0IHg9IjM3NC4xMDciIHk9IjMxNC4wODciIHRyYW5zZm9ybT0ibWF0cml4KC0wLjgzOTYgLTAuNTQzMyAwLjU0MzMgLTAuODM5NiA2MTEuNTYyNCA4MjQuNjIxOCkiIHN0eWxlPSJmaWxsOiNGRkZGRkY7IiB3aWR0aD0iMTA2Ljg4MiIgaGVpZ2h0PSIxNS44MzYiLz4NCgk8cmVjdCB4PSI0MTQuMzUxIiB5PSIxMDAuMjg5IiBzdHlsZT0iZmlsbDojRkZGRkZGOyIgd2lkdGg9IjM2Ljk0OCIgaGVpZ2h0PSIxNS44MzUiLz4NCgk8cmVjdCB4PSI0NDAuNzQyIiB5PSIxMzcuMjM3IiBzdHlsZT0iZmlsbDojRkZGRkZGOyIgd2lkdGg9IjM2Ljk0OCIgaGVpZ2h0PSIxNS44MzUiLz4NCgk8cmVjdCB4PSIzOS41ODgiIHk9Ijk1LjAxIiBzdHlsZT0iZmlsbDojRkZGRkZGOyIgd2lkdGg9IjM2Ljk0OCIgaGVpZ2h0PSIxNS44MzUiLz4NCgk8cmVjdCB4PSIxOTcuOTM4IiB5PSIxMDUuNTY3IiBzdHlsZT0iZmlsbDojRkZGRkZGOyIgd2lkdGg9IjM2Ljk0OCIgaGVpZ2h0PSIxNS44MzUiLz4NCgk8cmVjdCB4PSIzOS41ODgiIHk9IjI3NC40NzQiIHN0eWxlPSJmaWxsOiNGRkZGRkY7IiB3aWR0aD0iMzYuOTQ4IiBoZWlnaHQ9IjE1LjgzNSIvPg0KCTxyZWN0IHg9IjkyLjM3MSIgeT0iMjMyLjI0NyIgc3R5bGU9ImZpbGw6I0ZGRkZGRjsiIHdpZHRoPSIzNi45NDgiIGhlaWdodD0iMTUuODM1Ii8+DQoJPHJlY3QgeD0iMzg3Ljk1OSIgeT0iMTY4LjkwNyIgc3R5bGU9ImZpbGw6I0ZGRkZGRjsiIHdpZHRoPSIzNi45NDgiIGhlaWdodD0iMTUuODM1Ii8+DQo8L2c+DQo8L3N2Zz4=);
                background-position: center;
                background-repeat: no-repeat;
                background-size: cover;
            }
            .box {
                position: absolute;
                top: 50%;
                left: 50%;
                transform: translate(-50%,-50%);
                width: 650px;
                padding: 10px;
                background: rgba(0,0,0,.4);
                box-sizing: border-box;
                box-shadow: 0 15px 25px rgba(0,0,0,.5);
                border-radius: 10px;
                backdrop-filter: blur(7px);
            }
            .navbar-blur{
                -webkit-backdrop-filter: blur(7px);
                 backdrop-filter: blur(7px);
                 padding: 1px;
                 background-color:rgba(5, 0, 0, 0.37);
                 
            }
            button[type=SUBMIT] {
                border: none;
                color: white;
                padding: 16px 32px;
                text-decoration: none;
                margin: 4px 2px;
                cursor: pointer;
                font-size:120%;
            }
            .button2 {background-color: #af0c00d7;}
            .button1 {background-color: #01a887d2;}
            .button3 {background-color: #9c8c00c4;}
            td {text-align: center;}
            tr {text-align: center;}

        </style>
    </head>
    <body>
        <nav class="navbar-blur">
            <h1 style="font-size:250%;text-align:center;color:rgb(255, 255, 255);">ESP8266 RC Tank</h1>
          </nav>
        <div class="box">
            <CENTER>
                <FORM method="post" action="/form">
            <TABLE>
                <TR><TD>
                    <h3 style="text-align:center;color:rgb(255, 255, 255);">Forward & Back</h3>
                    <BUTTON class="button1" TYPE=SUBMIT VALUE="ON1" name=submit><<🢀<<</BUTTON>
                    <BUTTON class="button1" TYPE=SUBMIT VALUE="ON2" name=submit>>>🢂>></BUTTON>
                    <BUTTON class="button2" TYPE=SUBMIT VALUE="OFF12" name=submit>STOP</BUTTON>
                </TD></TR>
                <TR><TD>
                    <h3 style="text-align:center;color:rgb(255, 255, 255);">Turret Turning</h3>
                    <BUTTON class="button1" TYPE=SUBMIT VALUE="ON3" name=submit><<🢀<<</BUTTON>
                    <BUTTON class="button1" TYPE=SUBMIT VALUE="ON4" name=submit>>>🢂>></BUTTON>
                    <BUTTON class="button2" TYPE=SUBMIT VALUE="OFF34" name=submit>STOP</BUTTON>
                </TD></TR>
            </TABLE>
            <TABLE>
                <TR><TD>
                    <h3 style="text-align:center;color:rgb(255, 255, 255);">Gun Control</h3>
                    <BUTTON class="button2" TYPE=SUBMIT VALUE="ON5" name=submit>FIRE GUN</BUTTON>
                    <BUTTON class="button3" TYPE=SUBMIT VALUE="OFF5" name=submit>STOP FIRE</BUTTON>
                    </TD></TR>
                <TR><TD>
                    <h3 style="text-align:center;color:rgb(255, 255, 255);">Light Control</h3>
                    <BUTTON class="button1" TYPE=SUBMIT VALUE="ON6" name=submit>ON</BUTTON>
                    <BUTTON class="button2" TYPE=SUBMIT VALUE="OFF6" name=submit>OFF</BUTTON>
                    </TD></TR>
                <TR><TD>
                    <h3 style="text-align:center;color:rgb(255, 255, 255);">Siren Control</h3>
                    <BUTTON class="button3" TYPE=SUBMIT VALUE="ON7" name=submit>Press For Siren</BUTTON>
                    </TD></TR>
            </TABLE>
        </FORM>
        </CENTER>
        </div>
    </body>
</html>
)=====";
