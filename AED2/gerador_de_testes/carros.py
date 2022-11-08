from random import randrange, random

def carros():

    car_lis = [
    {
        "marca": "Audi",
        "carros":["A3","A3 Sedan","Q3","TT","A1","R8","A4","A5","A6","A7","Q5","Q7","Senna"]
    },    
    {
        "marca": "BMW",
        "carros":["Série 1","Série 3","X1","X3","X4","Z3","Z4","Série 2","Série 4","Série 5","Série 7","Série 8","X2","X5","X6","M2 Competition","M3 Sedã","M4 Coupé","M5","X6M","i3"]
    },    
    {
        "marca": "Chery",
        "carros":["Arrizzo","Celer","QQ","Tiggo 2","Tiggo 7","Face","Cielo","Arrizo 5E"]
    },    
    {
        "marca": "Chevrolet",
        "carros":["A-10","A-20","Alvorada","Amazona","Astra","Beretta","Blazer","Bonanza","Bolt","C-10","C-14","C-1416","C-15","C-20","Camaro","Caravan","Celta","Chevette Hatch","Chevette","Chevette Junior","Chevy","Cobalt","Corisco","Corsa","Corsa Sedan Classic","Corsa Pick-up","Corsa Wagon","Cruze","Cruze Sport6","D-10","D-20","Ipanema","Kadett","Kadett Conversível","Marajó ","Meriva ","Montana","Monza Sedan","Monza Hatch","Omega","Onix","Opala Coupé","Opala","Prisma","Silverado","S10 ","Spin","Suprema","TrailBlazer","Vectra","Vectra GT","Veraneio","Volt","Zafira","Equinox","SS10","Caprice","Malibu"]
    },
    {
        "marca": "Citroen",
        "carros":["Aircross","C3","C4 Cactus","Xsara Picasso","DS3","Xantia","C5","C4 Pallas","C4 Lounge","DS5","C3 Picasso","XM","ZX"]
    }, 
    {
        "marca": "Fiat",
        "carros":["147","Argo","Brava","Bravo","City","Cronos","Doblò","Ducato","Elba","Fiorino","Idea","Linea","Marea","Marea Weekend","Mob","Ogg","Palio","Weekend/Palio Weekend","Panorama","Prêmio","Punto","Siena/Grand Siena","Spazio","Stilo","Strada","Tempra","Tipo","Toro","Uno/Mille","Coupé"]
    }, 
    {
        "marca": "Ford",
        "carros":["Belina","Belina II","Corcel","Corcel II","Courier","Courier Van","Del Rey","Del Rey Scala","EcoSport","Escort","Escort SW","Escort conversível","F-100","F-1000","F-250","F-75","Fiesta","Focus","Jeep","Galaxie 500","Galaxie 197","Ka","Ka+","LTD","LTD Landau/Landau","Maverick","Mustang","Mondeo","Pampa","Ranger","Royale","Rural","Verona","Versailles","Fusion","Edge","Taurus","Crown Victoria"]
    }, 
    {
        "marca": "Honda",
        "carros":["Accord","City","Civic","Fit","CR-V","HR-V","WR-V","NSX"]
    },
    {
        "marca": "Hyundai",
        "carros":["Creta","HB20","HB20S","HB20X","ix20","ix35","Tucson","Azera","Velo","Santa Fe","Veracruz","Genesis","Elantra","Equus","Sonata"]
    },
    {
        "marca": "Volkswagen",
        "carros":["1600","Apollo","Amarok","Brasília","Fox","Fusca","Gol","Golf","Jetta","Karmann Ghia","Karmann Ghia Cabriolet","Karmann Ghia TC","Kombi","Logus","Parati","Passat","Pointer","Polo","Polo Classic","Polo Sedan","Quantum","Santana","Saveiro","SP1","SP2","TL","Up!","Variant","Variant II","Virtus","Voyage","Bora","T-Cross","Tiguan","Touareg"]
    },  
    
    ]

    car = randrange(0,9)

    car_dev = car_lis[car]

    index_car = randrange(0,len(car_dev["carros"])-1)
    
    c_ret = car_dev["carros"][index_car]

    return {
        "marca": car_dev["marca"],
        "carro": c_ret,
        "placa": f"{chr(randrange(65,90))}{chr(randrange(65,90))}{chr(randrange(65,90))}{randrange(0,9)}{chr(randrange(65,90))}{randrange(0,9)}{randrange(0,9)}",
        "ano": randrange(1999,2023),
        "km": float( f"{(randrange(0,1000) + (random())):.2f}")
    }
    

    