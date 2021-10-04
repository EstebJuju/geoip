# Géolocalisation adresses IP

## Objectif

écrire un programme permettant de déterminer le pays d'origine d'une adresse IP.
```bash
$ ./geoip 109.190.106.174
FR
```
## Fichier de données
vous disposez du fichier geoip.csv contenant la géolocalisation en fonctin de l'adresse IP.


### Database Fields
```
Name 	        Type 	Description
ip_from 	    INT (10) 	    First IP address show netblock.
ip_to 	        INT (10) 	    Last IP address show netblock.
country_code 	CHAR(2) 	    Two-character country code based on ISO 3166.
country_name 	VARCHAR(64) 	Country name based on ISO 3166.
region_name 	VARCHAR(128) 	Region or state name.
city_name 	    VARCHAR(128) 	City name.
latitude 	    DOUBLE 	        City latitude. Default to capital city latitude if city is unknown.
longitude 	    DOUBLE 	        City longitude. Default to capital city longitude if city is unknown.

une adresse sous la forme ip0.ip1.ip2.ip3 est convertie sous la forme d'un int en appliquant le calcul suivant :
ip = ip3 + ip2 * 256 + ip1 * 256 * 256 + ip0 * 256 * 256 * 256

```
