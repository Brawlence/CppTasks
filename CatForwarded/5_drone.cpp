//------------------------------------------------------------------------------
// 5. [15 marks]
//
// You are implementing simple 'waypoint' following for an AI hover drone
// in a 3D environment. The drone will consider a destination waypoint
// acceptable if it is both:
// i. Less than 10 units away.
// ii. Inside a 60 degree cone centered around the drone's 'forward' vector.
//
// Implement the function testWayPoint() shown below. If the waypoint is not
// acceptable the method should return REJECTED, otherwise it should return the
// side that the waypoint is on. This is defined with respect to the drone's
// forward vector and the world up vector (you may choose either 'handedness').

// You may assume the following methods and structures are defined:

// Add v and w, putting the result in sum : sum = v + w
void add(const Vector3& v, const Vector3& w, Vector3& sum);

// Subtract w from v, putting the result in diff: diff = v - w
void subtract(const Vector3& v, const Vector3& w, Vector3& diff);

// Compute dot product of Vector3 v and w
float dot(const Vector3& v, const Vector3& w);

// Compute v X w (cross product): crossOut = v X w
void cross(const Vector3& v, const Vector3& w, Vector3& crossOut);

// Normalize the Vector3 v to unit length
void normalize(Vector3& v);

// Compute length of Vector3
float length(const Vector3& v);

enum Direction
{
	REJECTED = 0,
	RIGHT,
	LEFT
};

// This is the method you must implement:
Direction testWayPoint(const Vector3& dronePosition, const Vector3& droneForward, const Vector3& targetWaypoint, const Vector3& worldUp );