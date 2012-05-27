/*
 *	server/zone/managers/creature/CreatureManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef CREATUREMANAGER_H_
#define CREATUREMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {

class MessageCallback;

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class NonPlayerCreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiAgent;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class Creature;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class CreatureTemplateManager;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace objects {
namespace area {

class SpawnArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#include "server/zone/managers/creature/CreatureMap.h"

#include "server/zone/managers/creature/SpawnAreaMap.h"

#include "server/zone/managers/creature/AiMap.h"

#include "server/zone/managers/ZoneManager.h"

#include "system/util/Vector.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class CreatureManager : public ZoneManager {
public:
	CreatureManager(Zone* planet);

	void initialize();

	TangibleObject* spawnLair(unsigned int lairTemplate, int minDifficulty, int maxDifficulty, float x, float z, float y);

	CreatureObject* spawnCreatureWithLevel(unsigned int mobileTemplateCRC, int level, float x, float z, float y, unsigned long long parentID = 0);

	CreatureObject* spawnCreature(unsigned int templateCRC, float x, float z, float y, unsigned long long parentID = 0);

	CreatureObject* spawnCreature(unsigned int templateCRC, unsigned int objectCRC, float x, float z, float y, unsigned long long parentID = 0, bool persistent = false);

	CreatureObject* createCreature(unsigned int templateCRC, bool persistent = false);

	void placeCreature(CreatureObject* creature, float x, float z, float y, unsigned long long parentID);

	int notifyDestruction(TangibleObject* destructor, AiAgent* destructedObject, int condition);

	void loadSpawnAreas();

	void loadAiTemplates();

	void loadSingleSpawns();

	void loadTrainers();

	void loadMissionSpawns();

	void loadInformants();

	void spawnRandomCreaturesAround(SceneObject* creature);

	void spawnRandomCreature(int number, float x, float z, float y, unsigned long long parentID = 0);

	void harvest(Creature* creature, CreatureObject* player, int selectedID);

	void addToReservePool(AiAgent* agent);

	int getSpawnedRandomCreatures();

	Vector<ManagedReference<SpawnArea* > >* getWorldSpawnAreas();

	Vector<float>* getTrainerObjectsX();

	Vector<float>* getTrainerObjectsY();

	Vector<String>* getTrainerZone();

	SpawnArea* getSpawnArea(const String& areaname);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	CreatureManager(DummyConstructorParameter* param);

	virtual ~CreatureManager();

	friend class CreatureManagerHelper;
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class CreatureManagerImplementation : public ZoneManagerImplementation {
protected:
	ManagedWeakReference<Zone* > zone;

	SpawnAreaMap spawnAreaMap;

	Reference<AiMap* > aiMap;

	Reference<CreatureTemplateManager* > creatureTemplateManager;

	SortedVector<ManagedReference<AiAgent* > > reservePool;

	int spawnedRandomCreatures;

public:
	CreatureManagerImplementation(Zone* planet);

	CreatureManagerImplementation(DummyConstructorParameter* param);

	void initialize();

	TangibleObject* spawnLair(unsigned int lairTemplate, int minDifficulty, int maxDifficulty, float x, float z, float y);

	CreatureObject* spawnCreatureWithLevel(unsigned int mobileTemplateCRC, int level, float x, float z, float y, unsigned long long parentID = 0);

	CreatureObject* spawnCreature(unsigned int templateCRC, float x, float z, float y, unsigned long long parentID = 0);

	CreatureObject* spawnCreature(unsigned int templateCRC, unsigned int objectCRC, float x, float z, float y, unsigned long long parentID = 0, bool persistent = false);

	CreatureObject* createCreature(unsigned int templateCRC, bool persistent = false);

	void placeCreature(CreatureObject* creature, float x, float z, float y, unsigned long long parentID);

	int notifyDestruction(TangibleObject* destructor, AiAgent* destructedObject, int condition);

	void loadSpawnAreas();

	void loadAiTemplates();

	void loadSingleSpawns();

	void loadTrainers();

	void loadMissionSpawns();

	void loadInformants();

private:
	bool createCreatureChildrenObjects(CreatureObject* creature, bool persistent = false);

public:
	void spawnRandomCreaturesAround(SceneObject* creature);

	void spawnRandomCreature(int number, float x, float z, float y, unsigned long long parentID = 0);

private:
	void setCreatureTemplateManager();

public:
	void harvest(Creature* creature, CreatureObject* player, int selectedID);

	void addToReservePool(AiAgent* agent);

	int getSpawnedRandomCreatures();

	Vector<ManagedReference<SpawnArea* > >* getWorldSpawnAreas();

	Vector<float>* getTrainerObjectsX();

	Vector<float>* getTrainerObjectsY();

	Vector<String>* getTrainerZone();

	SpawnArea* getSpawnArea(const String& areaname);

	WeakReference<CreatureManager*> _this;

	operator const CreatureManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~CreatureManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class CreatureManager;
};

class CreatureManagerAdapter : public ZoneManagerAdapter {
public:
	CreatureManagerAdapter(CreatureManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	TangibleObject* spawnLair(unsigned int lairTemplate, int minDifficulty, int maxDifficulty, float x, float z, float y);

	CreatureObject* spawnCreatureWithLevel(unsigned int mobileTemplateCRC, int level, float x, float z, float y, unsigned long long parentID);

	CreatureObject* spawnCreature(unsigned int templateCRC, float x, float z, float y, unsigned long long parentID);

	CreatureObject* spawnCreature(unsigned int templateCRC, unsigned int objectCRC, float x, float z, float y, unsigned long long parentID, bool persistent);

	CreatureObject* createCreature(unsigned int templateCRC, bool persistent);

	void placeCreature(CreatureObject* creature, float x, float z, float y, unsigned long long parentID);

	void loadSpawnAreas();

	void loadAiTemplates();

	void loadSingleSpawns();

	void loadTrainers();

	void loadMissionSpawns();

	void loadInformants();

	void spawnRandomCreaturesAround(SceneObject* creature);

	void spawnRandomCreature(int number, float x, float z, float y, unsigned long long parentID);

	void harvest(Creature* creature, CreatureObject* player, int selectedID);

	void addToReservePool(AiAgent* agent);

	int getSpawnedRandomCreatures();

	SpawnArea* getSpawnArea(const String& areaname);

};

class CreatureManagerHelper : public DistributedObjectClassHelper, public Singleton<CreatureManagerHelper> {
	static CreatureManagerHelper* staticInitializer;

public:
	CreatureManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CreatureManagerHelper>;
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

#endif /*CREATUREMANAGER_H_*/
