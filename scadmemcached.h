#ifndef SCADMEMCACHED_H
#define SCADMEMCACHED_H

extern "C" {
    #include <libmemcached/memcached.h>
}
#include <QString>
#include <QDebug>

class scadMemcached
{
public:
    scadMemcached();
    bool setCacheData(QString key, QString value);
    bool getCacheData(QString key,QString &value,size_t &value_length,uint32_t &flags);
    bool addServers();

private:
    memcached_server_st *servers = NULL;
    memcached_st *memc;
    memcached_return rc;
};

#endif // SCADMEMCACHED_H
