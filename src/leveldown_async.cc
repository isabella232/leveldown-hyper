#include <hyperleveldb/db.h>

#include "leveldown.h"
#include "leveldown_async.h"

namespace leveldown {

/** DESTROY WORKER **/

DestroyWorker::DestroyWorker (
    Nan::Utf8String* location
  , Nan::Callback *callback
) : AsyncWorker(NULL, callback, "leveldown-hyper:destroy")
  , location(location)
{};

DestroyWorker::~DestroyWorker () {
  delete location;
}

void DestroyWorker::Execute () {
  leveldb::Options options;
  SetStatus(leveldb::DestroyDB(**location, options));
}

/** REPAIR WORKER **/

RepairWorker::RepairWorker (
    Nan::Utf8String* location
  , Nan::Callback *callback
) : AsyncWorker(NULL, callback, "leveldown-hyper:repair")
  , location(location)
{};

RepairWorker::~RepairWorker () {
  delete location;
}

void RepairWorker::Execute () {
  leveldb::Options options;
  SetStatus(leveldb::RepairDB(**location, options));
}

} // namespace leveldown
