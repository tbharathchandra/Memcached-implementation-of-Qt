#include "scadmemcached.h"

scadMemcached::scadMemcached()
{

}

bool scadMemcached::addServers(){
    memc = memcached_create(NULL);
    servers = memcached_server_list_append(servers,"localhost",11211,&rc);
    rc = memcached_server_push(memc,servers);

    if(rc==MEMCACHED_SUCCESS){
        qDebug()<<"Added server successfully\n";
        return true;
    }else{
        qDebug()<<"couldn't add server\n";
        return false;
    }
}

bool scadMemcached::setCacheData(QString key, QString value){
    char *ckey = key.toLocal8Bit().data();
    char *cvalue = value.toLocal8Bit().data();
    rc = memcached_set(memc, ckey, key.length(), cvalue, value.length(), (time_t)0, (uint32_t)0);
    if(rc==MEMCACHED_SUCCESS) return true;
    else return false;
}

bool scadMemcached::getCacheData(QString key,QString &value,size_t &value_length,uint32_t &flags){
    char *ckey = key.toLocal8Bit().data();
    char *cvalue = memcached_get(memc, ckey, key.length(), &value_length, &flags,&rc);
    if(rc==MEMCACHED_SUCCESS){
        value = QString::fromUtf8(cvalue);
        return true;
    }else return false;

}



