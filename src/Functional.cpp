//
// Created by doria on 01/07/2024.
//

#include "../include/Functional.h"

int calculateHorizontalVelocity(const EntityState& state) {
    if (state.KeyRight) {
        int newVelocity = state.horizontalVelocity + 20;
        return newVelocity > state.speed ? state.speed : newVelocity;
    } else if (state.KeyLeft) {
        int newVelocity = state.horizontalVelocity - 20;
        return newVelocity < -state.speed ? -state.speed : newVelocity;
    }
    return 0;
}

bool calculateLookingDirection(const EntityState& state) {
    if (state.KeyRight) {
        return false;
    } else if (state.KeyLeft) {
        return true;
    }
    return state.lookingDirection;
}

qreal calculateNewPositionX(qreal x, int horizontalVelocity) {
    return x + horizontalVelocity;
}

int calculateVerticalVelocity(const GravityState& state) {
    if (state.collideTop) {
        return 0;
    }
    if (!state.OnFloor && state.KeyUp) {
        if (state.verticalVelocity > 0) {
            return (state.verticalVelocity + state.dt * state.gravity_const * 2) * 0.9;
        }
        return state.verticalVelocity + state.dt * state.gravity_const * 2;
    }
    if (!state.OnFloor && !state.KeyUp) {
        return state.verticalVelocity + state.dt * state.gravity_const * 4;
    }
    return state.verticalVelocity;
}

qreal calculateNewPositionY(const GravityState& state) {
    if (!state.OnFloor) {
        return state.y + state.dt * state.verticalVelocity;
    }
    return state.y;
}
